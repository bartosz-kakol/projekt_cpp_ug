#pragma once

#include <functional>

#include "World/Base/Interfaces/IIdentifier.h"
#include "World/Base/Interfaces/IWorld.h"

class Creator {
    IWorld& world;
    IIdentifier& identifier;
public:
    Creator(IWorld& world, IIdentifier& identifier);

    template<typename OrganismT, typename BehaviorT>
    void createOrganism();

    template <typename OrganismT, typename BehaviorT>
    void createOrganism(std::function<void(OrganismT*, BehaviorT*)> init);
};

#include "Creator.tpp"
