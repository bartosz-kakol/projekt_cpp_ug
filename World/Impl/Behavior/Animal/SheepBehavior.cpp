#include "SheepBehavior.h"

#include "World/Impl/Animal/Sheep.h"
#include "World/Impl/Behavior/AnimalBehavior.h"
#include "World/Models/ActionContext.h"

void SheepBehavior::behave(const ActionContext ctx)
{
    AnimalBehavior(
        [](const int id, const int birthTurn)
        {
            return std::make_pair(
                std::make_unique<Sheep>(id, birthTurn),
                std::make_unique<SheepBehavior>()
            );
        }
    ).behave(ctx);
}

std::string SheepBehavior::getName() const
{
    return "SheepBehavior";
}
