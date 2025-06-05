#pragma once

template <typename OrganismT, typename BehaviorT>
OrganismT* Creator::createOrganism()
{
    return createOrganism<OrganismT, BehaviorT>([](auto*, auto*) {});
}

template <typename OrganismT, typename BehaviorT>
OrganismT* Creator::createOrganism(std::function<void(OrganismT*, BehaviorT*)> init)
{
    static_assert(std::is_base_of_v<IOrganism, OrganismT>,
                  "OrganismT musi dziedziczyć pod IOrganism");
    static_assert(std::is_base_of_v<IBehavior, BehaviorT>,
                  "BehaviorT musi dziedziczyć pod IBehavior");

    auto organism = std::make_unique<OrganismT>(world.getIdentifier()->next());
    organism->init();
    auto behavior = std::make_unique<BehaviorT>();

    const auto organismPtr = organism.get();
    init(organismPtr, behavior.get());

    world.addOrganism(std::move(organism), std::move(behavior));

    return organismPtr;
}