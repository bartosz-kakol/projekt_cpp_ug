#pragma once

#include <memory>
#include <vector>

#include "World/Base/Interfaces/IIdentifier.h"
#include "World/Base/Interfaces/IWorld.h"
#include "World/Base/Interfaces/IOrganism.h"
#include "World/Base/Interfaces/IBehavior.h"
#include "World/Models/OrganismRecord.h"

class World final : public IWorld {
    int width;
    int height;
    int turn;
    std::vector<OrganismRecord> organisms;
    std::vector<OrganismRecord> queue;
    std::unique_ptr<IIdentifier> identifier;

    std::unordered_map<std::string, std::function<std::unique_ptr<IOrganism>()>> serializationOrganismCreators;
    std::unordered_map<std::string, std::function<std::unique_ptr<IBehavior>()>> serializationBehaviorCreators;

    bool isPositionOnWorld(int x, int y) const;

    bool isPositionFree(int x, int y, bool includeQueue = false) const;
public:
    World(std::unique_ptr<IIdentifier> identifier, int width, int height);
    explicit World(std::unique_ptr<IIdentifier> identifier);

    int getWidth() const override;
    void setWidth(int width);

    int getHeight() const override;
    void setHeight(int height);

    int getTurn() const override;

    IIdentifier* getIdentifier() const override;

    void addOrganism(std::unique_ptr<IOrganism> organism, std::unique_ptr<IBehavior> behavior) override;
    void queueOrganism(std::unique_ptr<IOrganism> organism, std::unique_ptr<IBehavior> behavior) override;
    void releaseOrganismQueue() override;
    void removeOrganism(int id) override;

    void clear() override;

    std::vector<Position> getVectorOfFreePositionsAround(Position position) const override;
    std::vector<Position> getVectorOfPositionsAround(Position position) const override;
    std::vector<IOrganism*> getOrganismsFromPosition(int x, int y, bool includeQueue) const override;
    std::vector<IOrganism*> getOrganismsFromPosition(int x, int y) const override;

    void makeTurn() override;

    template<typename OrganismT>
    void registerSerializationOrganismCreator(const std::string& species);

    template<typename BehaviorT>
    void registerSerializationBehaviorCreator(const std::string& name);

    void serialize(Variant& v) override;
    void deserialize(Variant& source) override;
};

#include "World.tpp"
