#include "GrassBehavior.h"

#include "World/Impl/Behavior/PlantBehavior.h"
#include "World/Impl/Plant/Grass.h"
#include "World/Models/ActionContext.h"

void GrassBehavior::behave(const ActionContext ctx)
{
    PlantBehavior(
        [](const int id, const int birthTurn)
        {
            return std::make_pair(
                std::make_unique<Grass>(id, birthTurn),
                std::make_unique<GrassBehavior>()
            );
        }
    ).behave(ctx);
}

std::string GrassBehavior::getName() const
{
    return "GrassBehavior";
}
