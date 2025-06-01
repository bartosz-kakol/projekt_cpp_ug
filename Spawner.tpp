#pragma once

#include "World/Base/Interfaces/IBehavior.h"
#include "World/Base/Interfaces/IOrganism.h"

template<typename OrganismT, typename BehaviorT>
void Spawner::map(const std::string& name)
{
    static_assert(std::is_base_of_v<IOrganism, OrganismT>,
                  "OrganismT musi dziedziczyć pod IOrganism");
    static_assert(std::is_base_of_v<IBehavior, BehaviorT>,
                  "BehaviorT musi dziedziczyć pod IBehavior");

    mappings[name] = [this](SpawnSettings settings)
    {
        creator.createOrganism<OrganismT, BehaviorT>(
            [settings](OrganismT* organism, [[maybe_unused]] BehaviorT* behavior) {
                organism->setPosition(settings.position);
            }
        );
    };
}
