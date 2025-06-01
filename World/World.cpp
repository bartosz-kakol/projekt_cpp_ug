#include "World.h"

#include <iostream>

#include "Base/ActionBase.h"
#include "World/Models/Position.h"
#include "World/Models/OrganismRecord.h"
#include "World/Models/ActionContext.h"

World::World(const int width, const int height)
    : width(width), height(height) { }

World::World()
    : World(6, 6) { }

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

bool World::isPositionOnWorld(const int x, const int y) const {
    return (x >= 0 && y >= 0 && x < getWidth() && y < getHeight());
}

bool World::isPositionFree(const Position position) const {
    return this->getOrganismsFromPosition(position.getX(), position.getY()).empty();
}

void World::addOrganism(std::unique_ptr<IOrganism> organism, std::unique_ptr<IBehavior> behavior)
{
    organisms.emplace_back(OrganismRecord{
        .organism = std::move(organism),
        .behavior = std::move(behavior)
    });
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

std::vector<Position> World::getVectorOfFreePositionsAround(const Position position) const {
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

    const auto iter = std::remove_if(
        result.begin(), result.end(),
        [this](const Position pos) {
            return !isPositionFree(pos);
        }
    );
    result.erase(iter, result.end());

    return result;
}

std::vector<Position> World::getVectorOfPositionsAround(const Position position) const {
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

std::vector<IOrganism*> World::getOrganismsFromPosition(int x, int y) const {
    std::vector<IOrganism*> result;
    for (const auto& [org, _] : organisms) {
        if (org->getPosition().getX() == x && org->getPosition().getY() == y) {
            result.push_back(org.get());
        }
    }
    return result;
}

void World::makeTurn() {
    std::sort(
        organisms.begin(), organisms.end(),
        [](const OrganismRecord& a, const OrganismRecord& b)
        {
            return a.organism->getInitiative() > b.organism->getInitiative();
        }
    );

    std::cout << "TURA ------------------------" << std::endl;

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
        org->setPower(org->getPower() + 1);
        org->setLiveLength(org->getLiveLength() - 1);

        if (org->getLiveLength() == 0)
        {

        }
    }

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
    std::cout << "------------------------ TURA" << std::endl << std::endl;
}

void World::writeWorld(const std::string& fileName) {
    // TODO: Implementacja zapisu świata do pliku binarnego
}

void World::readWorld(std::string fileName) {
    // TODO: Implementacja odczytu świata z pliku binarnego
}

std::string World::toString() const {
    std::string result = "\nTura " + std::to_string(getTurn()) + "\n";

    for (int wY = 0; wY < getHeight(); ++wY) {
        for (int wX = 0; wX < getWidth(); ++wX) {
            if (const auto organisms = getOrganismsFromPosition(wX, wY); !organisms.empty())
            {
                const auto num = organisms[0]->getId() < 10 ?
                    std::to_string(organisms[0]->getId())
                    :
                    "X";

                result += std::string(1, organisms[0]->getSign()) + num;
            }
            else
            {
                result += separator;
            }

            result += ' ';
        }

        result += "\n";
    }

    return result;
}