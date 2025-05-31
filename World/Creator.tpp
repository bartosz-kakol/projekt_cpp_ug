#pragma once

#include <type_traits>

#include "Base/Interfaces/IIdentifier.h"

template <typename IdentifierT>
Creator<IdentifierT>::Creator(IWorld& world)
    : world(world), identifier(std::make_unique<IdentifierT>())
{
    static_assert(std::is_base_of_v<IIdentifier, IdentifierT>,
                  "IdentifierT musi dziedziczyć pod IIdentifier");
}

template <typename IdentifierT>
template <typename OrganismT, typename BehaviorT>
void Creator<IdentifierT>::createOrganism()
{
    createOrganism<OrganismT, BehaviorT>([](auto*, auto*) {});
}

template <typename IdentifierT>
template <typename OrganismT, typename BehaviorT>
void Creator<IdentifierT>::createOrganism(std::function<void(OrganismT*, BehaviorT*)> init)
{
    static_assert(std::is_base_of_v<IOrganism, OrganismT>,
                  "OrganismT musi dziedziczyć pod IOrganism");
    static_assert(std::is_base_of_v<IBehavior, BehaviorT>,
                  "BehaviorT musi dziedziczyć pod IBehavior");

    const auto id = identifier->next();

    auto organism = std::make_unique<OrganismT>(id);
    organism->init();
    auto behavior = std::make_unique<BehaviorT>();

    init(organism.get(), behavior.get());

    world.addOrganism(std::move(organism), std::move(behavior));
}