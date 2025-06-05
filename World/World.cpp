#include "World.h"

#include <iostream>

#include "Base/ActionBase.h"
#include "World/Models/Position.h"
#include "World/Models/OrganismRecord.h"
#include "World/Models/ActionContext.h"

World::World(std::unique_ptr<IIdentifier> identifier, const int width, const int height)
    : width(width), height(height), turn(0), identifier(std::move(identifier))
{

}

World::World(std::unique_ptr<IIdentifier> identifier)
    : World(std::move(identifier), 6, 6)
{

}

int World::getWidth() const {
    return this->width;
}

void World::setWidth(const int width) {
    this->width = width;
}

int World::getHeight() const {
    return this->height;
}

void World::setHeight(const int height) {
    this->height = height;
}

int World::getTurn() const {
    return this->turn;
}

IIdentifier* World::getIdentifier() const
{
    return this->identifier.get();
}

bool World::isPositionOnWorld(const int x, const int y) const {
    return x >= 0 && y >= 0 && x < getWidth() && y < getHeight();
}

bool World::isPositionFree(const int x, const int y, const bool includeQueue) const {
    return this->getOrganismsFromPosition(x, y, includeQueue).empty();
}

void World::addOrganism(std::unique_ptr<IOrganism> organism, std::unique_ptr<IBehavior> behavior)
{
    organisms.emplace_back(OrganismRecord{
        .organism = std::move(organism),
        .behavior = std::move(behavior)
    });
}

void World::queueOrganism(std::unique_ptr<IOrganism> organism, std::unique_ptr<IBehavior> behavior)
{
    queue.emplace_back(OrganismRecord{
        .organism = std::move(organism),
        .behavior = std::move(behavior)
    });
}

void World::releaseOrganismQueue()
{
    for (auto& [organism, behavior] : queue) {
        if (organism == nullptr) {
            // Może się wydarzyć, jeśli jakiś organizm usunął sam siebie podczas wykonywania swojego zachowania!
            continue;
        }

        addOrganism(std::move(organism), std::move(behavior));
    }

    queue.clear();
}

void World::removeOrganism(int id) {
    const auto iter = std::remove_if(
        organisms.begin(), organisms.end(),
        [id](const OrganismRecord& record)
        {
           return record.organism->getId() == id;
        }
    );
    organisms.erase(iter, organisms.end());
}

void World::clear()
{
    for (auto it = organisms.begin(); it != organisms.end(); ++it)
    {
        organisms.erase(it);
    }

    organisms.clear();
}

std::vector<Position> World::getVectorOfFreePositionsAround(const Position position) const
{
    auto result = getVectorOfPositionsAround(position);

    const auto iter = std::remove_if(
        result.begin(), result.end(),
        [this](const Position& pos) {
            return !isPositionFree(pos.getX(), pos.getY(), true);
        }
    );
    result.erase(iter, result.end());

    return result;
}

std::vector<Position> World::getVectorOfPositionsAround(const Position position) const
{
    const int pos_x = position.getX();
    const int pos_y = position.getY();

    std::vector<Position> result;
    for (int x = -1; x < 2; ++x) {
        for (int y = -1; y < 2; ++y) {
            if ((x != 0 || y != 0) && isPositionOnWorld(pos_x + x, pos_y + y)) {
                result.emplace_back(pos_x + x, pos_y + y);
            }
        }
    }

    return result;
}

std::vector<IOrganism*> World::getOrganismsFromPosition(const int x, const int y, const bool includeQueue) const
{
    std::vector<IOrganism*> result;

    for (const auto& [org, _] : organisms) {
        if (org->getPosition().getX() == x && org->getPosition().getY() == y) {
            result.push_back(org.get());
        }
    }

    if (includeQueue)
    {
        for (const auto& [org, _] : queue) {
            if (org->getPosition().getX() == x && org->getPosition().getY() == y) {
                result.push_back(org.get());
            }
        }
    }

    return result;
}

std::vector<IOrganism*> World::getOrganismsFromPosition(const int x, const int y) const
{
    return getOrganismsFromPosition(x, y, false);
}

void World::makeTurn() {
    std::sort(
        organisms.begin(), organisms.end(),
        [](const OrganismRecord& a, const OrganismRecord& b)
        {
            return a.organism->getInitiative() > b.organism->getInitiative();
        }
    );

    ActionBase::logger->log("");
    ActionBase::logger->log("Tura " + std::to_string(turn));

    for (const auto& [org, behavior] : organisms) {
        if (org == nullptr)
        {
            // Może się wydarzyć, jeśli jakiś poprzedni organizm usunął ten, który jest teraz przetwarzany!
            continue;
        }

        const ActionContext ctx{
            .world = *this,
            .organism = org.get()
        };
        behavior->behave(ctx);

        if (org == nullptr)
        {
            // Może się wydarzyć, jeśli organizm skasował sam siebie podczas wykonywania swojego zachowania!
            continue;
        }

        org->setPower(org->getPower() + 1);

        if (const auto liveLength = org->getLiveLength(); liveLength > -1)
        {
            org->setLiveLength(liveLength - 1);
        }
    }

    releaseOrganismQueue();

    // Usuwanie organizmów, które umarły ze starości
    const auto iter = std::remove_if(
        organisms.begin(), organisms.end(),
        [this](const OrganismRecord& record) {
            const auto& org = record.organism;

            if (org->getLiveLength() == 0) {
                ActionBase::logger->log(org->toString() + " umarło ze starości.");
                return true;
            }

            return false;
        }
    );
    organisms.erase(iter, organisms.end());

    turn++;
}

void World::serialize(Variant& v)
{
    v.addChild("turn", Variant::fromValue(turn));
    v.addChild("width", Variant::fromValue(width));
    v.addChild("height", Variant::fromValue(height));
    v.addChild("identifierState", Variant::fromValue(identifier->getState()));

    v.addChild("organisms", Variant::sequential());
    for (const auto& [organism, behavior] : organisms) {
        Variant record;

        const std::string& organismName = organism->getSpecies();
        record.addChild("organism", Variant::fromValue(organismName));

        const std::string& behaviorName = behavior->getName();
        record.addChild("behavior", Variant::fromValue(behaviorName));

        Variant data;
        organism->serialize(data);
        record.addChild("data", data);

        v.getChild("organisms").addSequentialChild(record);
    }
}

void World::deserialize(Variant& source)
{
    turn = source.getChild("turn").getValueAs<int>();
    width = source.getChild("width").getValueAs<int>();
    height = source.getChild("height").getValueAs<int>();
    identifier->setState(source.getChild("identifierState").getValueAs<int>());

    organisms.clear();
    organisms = source.getChild("organisms").getSequentialChildren<OrganismRecord>(
        [this](Variant& item)
        {
            OrganismRecord record;

            const auto& species = item.getChild("organism").getValueAs<std::string>();
            const auto& behavior = item.getChild("behavior").getValueAs<std::string>();

            if (serializationOrganismCreators.find(species) == serializationOrganismCreators.end()) {
                throw std::runtime_error("Nie znaleziono kreatora organizmu dla gatunku o nazwie: " + species);
            }

            record.organism = serializationOrganismCreators[species]();
            record.organism->deserialize(item.getChild("data"));

            if (serializationBehaviorCreators.find(behavior) == serializationBehaviorCreators.end()) {
                throw std::runtime_error("Nie znaleziono kreatora zachowania dla zachowania o nazwie: " + behavior);
            }

            record.behavior = serializationBehaviorCreators[behavior]();

            return record;
        }
    );
}
