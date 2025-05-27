#include "Sheep.h"

#include "ActionImpl/MoveRandomly.h"

void SheepBehavior::behave(Organism& self, World& world)
{
    world.invokeAction(typeid(MoveRandomly), self);
}

Sheep::Sheep(const int id, const Position position)
    : Animal('S', id, position, 3, 3, 10, 6)
{
    behavior = std::make_unique<SheepBehavior>();
}
