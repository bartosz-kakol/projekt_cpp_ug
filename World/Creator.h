#pragma once

#include <functional>

#include "World/Base/Interfaces/IWorld.h"

template<typename IdentifierT>
class Creator {
    IWorld& world;
    std::unique_ptr<IdentifierT> identifier;
public:
    explicit Creator(IWorld& world);

    template<typename OrganismT, typename BehaviorT>
    void createOrganism();

    template <typename OrganismT, typename BehaviorT>
    void createOrganism(std::function<void(OrganismT*, BehaviorT*)> init);
};

#include "Creator.tpp"
