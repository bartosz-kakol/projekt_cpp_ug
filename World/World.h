#pragma once

#include <memory>
#include <vector>
#include <string>

#include "World/Base/Interfaces/IWorld.h"
#include "World/Base/Interfaces/IOrganism.h"
#include "World/Base/Interfaces/IBehavior.h"
#include "World/Models/OrganismRecord.h"

class World final : public IWorld {
    int width;
    int height;
    int turn = 0;
    std::vector<OrganismRecord> organisms;
    std::string separator = "..";

    bool isPositionOnWorld(int x, int y) const;
    bool isPositionFree(Position position) const;

public:
    World(int width, int height);
    World();

    int getWidth() const;
    void setWidth(int width);

    int getHeight() const;
    void setHeight(int height);

    int getTurn() const;

    void addOrganism(std::unique_ptr<IOrganism> organism, std::unique_ptr<IBehavior> behavior) override;
    void removeOrganism(int id) override;

    std::vector<Position> getVectorOfFreePositionsAround(Position position) const override;
    std::vector<Position> getVectorOfPositionsAround(Position position) const override;
    std::vector<IOrganism*> getOrganismsFromPosition(int x, int y) const override;

    void makeTurn();

    void writeWorld(const std::string& fileName);

    void readWorld(std::string fileName);

    std::string toString() const;
};
