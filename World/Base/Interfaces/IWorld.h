#pragma once

#include <vector>

#include "World/Models/Position.h"
#include "World/Base/Interfaces/IOrganism.h"
#include "World/Base/Interfaces/IBehavior.h"

class IWorld {
public:
    virtual ~IWorld() = default;

    virtual std::vector<Position> getVectorOfFreePositionsAround(Position position) const = 0;

    virtual std::vector<Position> getVectorOfPositionsAround(Position position) const = 0;

    virtual std::vector<IOrganism*> getOrganismsFromPosition(int x, int y) const = 0;

    virtual void addOrganism(std::unique_ptr<IOrganism> organism, std::unique_ptr<IBehavior> behavior) = 0;

    virtual void removeOrganism(int id) = 0;
};
