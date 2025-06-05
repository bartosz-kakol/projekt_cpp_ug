#pragma once

#include <vector>

#include "World/Models/Position.h"
#include "World/Base/Interfaces/IOrganism.h"
#include "World/Base/Interfaces/IBehavior.h"
#include "World/Base/Interfaces/IIdentifier.h"

class IWorld : public ISerializable {
public:
    virtual ~IWorld() = default;

    virtual std::vector<Position> getVectorOfFreePositionsAround(Position position) const = 0;
    virtual std::vector<Position> getVectorOfPositionsAround(Position position) const = 0;

    virtual std::vector<IOrganism*> getOrganismsFromPosition(int x, int y, bool includeQueue) const = 0;
    virtual std::vector<IOrganism*> getOrganismsFromPosition(int x, int y) const = 0;

    virtual void addOrganism(std::unique_ptr<IOrganism> organism, std::unique_ptr<IBehavior> behavior) = 0;
    virtual void queueOrganism(std::unique_ptr<IOrganism> organism, std::unique_ptr<IBehavior> behavior) = 0;
    virtual void releaseOrganismQueue() = 0;
    virtual void removeOrganism(int id) = 0;
    virtual void removeOrganismSilently(int id) = 0;

    virtual void clear() = 0;

    virtual int getWidth() const = 0;

    virtual int getHeight() const = 0;

    virtual int getTurn() const = 0;

    virtual IIdentifier* getIdentifier() const = 0;

    virtual void makeTurn() = 0;
};
