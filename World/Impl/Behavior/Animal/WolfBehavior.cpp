#include "WolfBehavior.h"

#include "World/Impl/Animal/Wolf.h"
#include "World/Impl/Behavior/AnimalBehavior.h"
#include "World/Models/ActionContext.h"

void WolfBehavior::behave(const ActionContext ctx)
{
    AnimalBehavior(
        [](const int id, const int birthTurn)
        {
            return std::make_pair(
                std::make_unique<Wolf>(id, birthTurn),
                std::make_unique<WolfBehavior>()
            );
        }
    ).behave(ctx);
}

std::string WolfBehavior::getName() const
{
    return "WolfBehavior";
}
