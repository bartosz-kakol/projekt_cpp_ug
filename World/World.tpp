#pragma once

template <typename OrganismT>
void World::registerSerializationOrganismCreator(const std::string& species)
{
    static_assert(std::is_base_of_v<IOrganism, OrganismT>,
                  "OrganismT musi dziedziczyć pod IOrganism");

    serializationOrganismCreators[species] = []()
    {
        return std::make_unique<OrganismT>(-1);
    };
}

template <typename BehaviorT>
void World::registerSerializationBehaviorCreator(const std::string& name)
{
    static_assert(std::is_base_of_v<IBehavior, BehaviorT>,
                  "BehaviorT musi dziedziczyć pod IBehavior");

    serializationBehaviorCreators[name] = []
    {
        return std::make_unique<BehaviorT>();
    };
}
