#include "SheepBehavior.h"

#include "World/Impl/Animal/Sheep.h"
#include "World/Impl/Behavior/AnimalBehavior.h"
#include "World/Models/ActionContext.h"

void SheepBehavior::behave(const ActionContext ctx)
{
    AnimalBehavior(
        [](const int id)
        {
            return std::make_pair(
                std::make_unique<Sheep>(id),
                std::make_unique<SheepBehavior>()
            );
        }
    ).behave(ctx);
}

std::string SheepBehavior::getName() const
{
    return "SheepBehavior";
}
