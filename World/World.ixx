module;

#include <iostream>
#include <map>
#include <string>
#include <vector>

export module World;

import World.Base.Interfaces.IWorld;
import World.Base.Interfaces.IIdentifier;
import World.Base.Interfaces.IAction;
import World.Base.Interfaces.IBehavior;
import World.Base.Interfaces.IOrganism;
import World.Base.Organism;
import World.Models.Position;
import World.Models.OrganismRecord;

export class World final : public IWorld
{
    int width;
    int height;
    int turn = 0;
    std::vector<OrganismRecord> organisms{};
    char separator = '.';
    std::unique_ptr<IIdentifier> identifier;

    [[nodiscard]] bool isPositionOnWorld(const int x, const int y) const
    {
        return (x >= 0 && y >= 0 && x < getWidth() && y < getHeight());
    }

    [[nodiscard]] bool isPositionFree(const Position position) const
    {
        return this->getOrganismsFromPosition(position.getX(), position.getY()).empty();
    }

public:
    World(std::unique_ptr<IIdentifier> identifier, const int width, const int height)
        : width(width), height(height), identifier(std::move(identifier))
    {

    }

    explicit World(std::unique_ptr<IIdentifier> identifier)
        : World(std::move(identifier), 6, 6)
    {

    }

    [[nodiscard]] int getWidth() const
    {
        return this->width;
    }

    void setWidth(const int width)
    {
        this->width = width;
    }

    [[nodiscard]] int getHeight() const
    {
        return this->height;
    }

    void setHeight(const int height)
    {
        this->height = height;
    }

    [[nodiscard]] int getTurn() const
    {
        return this->turn;
    }

    template<typename OrganismT, typename BehaviorT> int createOrganism(const Position position) {
        static_assert(std::is_base_of_v<Organism, OrganismT>,
                      "Podany typ organizmu musi dziedziczyć po klasie Organism.");

        static_assert(std::is_base_of_v<IBehavior, BehaviorT>,
                      "Podany typ zachowania musi dziedziczyć po klasie IBehavior.");

        auto organism = std::make_unique<OrganismT>(identifier->next());
        organism->setPosition(position);
        organism->init();

        auto behavior = std::make_unique<BehaviorT>();

        const int id = organism->getId();
        organisms.emplace_back(std::move(organism), std::make_unique<BehaviorT>());

        return id;
    }

    void removeOrganism(int id)
    {
        std::erase_if(
            organisms,
            [id](const OrganismRecord& record)
            {
                return record.organism->getId() == id;
            }
        );
    }

    [[nodiscard]] std::vector<Position> getVectorOfFreePositionsAround(const Position position) const override
    {
        const int pos_x = position.getX();
        const int pos_y = position.getY();

        std::vector<Position> result;

        for (int x = -1; x < 2; ++x)
        {
            for (int y = -1; y < 2; ++y)
            {
                if (
                    (x != 0 || y != 0) &&
                    isPositionOnWorld(pos_x + x, pos_y + y)
                ) {
                    result.emplace_back(pos_x + x, pos_y + y);
                }
            }
        }

        const auto iter = std::ranges::remove_if(
            result,
             [this](const Position pos)
             {
                 return !isPositionFree(pos);
             }
        ).begin();
        result.erase(iter, result.end());

        return result;
    }

    [[nodiscard]] std::vector<IOrganism*> getOrganismsFromPosition(const int x, const int y) const override
    {
        std::vector<IOrganism*> result;

        for (const auto& [org, _] : organisms)
        {
            if (org->getPosition().getX() == x && org->getPosition().getY() == y)
            {
                result.push_back(org.get());
            }
        }

        return result;
    }

    void makeTurn()
    {
        // Sortowanie organizmów po inicjatywie (malejąco)
        std::ranges::sort(
            organisms,
            [](const OrganismRecord& a, const OrganismRecord& b) {
                return a.organism->getInitiative() > b.organism->getInitiative();
            }
        );

        std::cout << "TURA ------------------------" << std::endl;

        for (const auto& [org, behavior] : organisms) {
            std::cout << "\tOrganizm " << org->getSign() << org->getId() << ":" << std::endl;

            behavior->behave(*org, *this);
            org->setPower(org->getPower() + 1);
            org->setLiveLength(org->getLiveLength() - 1);

            std::cout << std::endl;
        }

        const auto iter = std::ranges::remove_if(
            organisms,
             [this](const OrganismRecord& record)
             {
                 if (const auto& org = record.organism; org->getLiveLength() == 0)
                 {
                     std::cout << org->getSign() << org->getId() << " umarło ze starości." << std::endl;
                     return true;
                 }

                 return false;
             }
        ).begin();
        organisms.erase(iter, organisms.end());

        turn++;
        std::cout << "------------------------ TURA" << std::endl;
    }

    void writeWorld(const std::string& fileName)
    {
        // TODO: Implementacja zapisu świata do pliku binarnego
    }

    void readWorld(std::string fileName)
    {
        // TODO: Implementacja odczytu świata z pliku binarnego
    }

    [[nodiscard]] std::string toString() const
    {
        std::string result = "\nTura " + std::to_string(getTurn()) + "\n";

        for (int wY = 0; wY < getHeight(); ++wY) {
            for (int wX = 0; wX < getWidth(); ++wX) {
                if (const auto organisms = getOrganismsFromPosition(wX, wY); !organisms.empty())
                    result += organisms[0]->getSign();
                else
                    result += separator;

                result += ' ';
            }

            result += "\n";
        }

        return result;
    }
};
