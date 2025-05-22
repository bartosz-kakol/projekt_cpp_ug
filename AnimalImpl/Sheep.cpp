#include "Sheep.h"

void SheepBehavior::act(Organism& self, World& world)
{
    return ;
}

Sheep::Sheep(const Position position)
    : Animal(3, 3, 10, 6, position, 'S')
{
    behavior = std::make_unique<SheepBehavior>();
}
