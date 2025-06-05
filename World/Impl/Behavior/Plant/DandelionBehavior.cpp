#include "DandelionBehavior.h"

#include "World/Impl/Behavior/PlantBehavior.h"
#include "World/Impl/Plant/Dandelion.h"
#include "World/Models/ActionContext.h"

void DandelionBehavior::behave(const ActionContext ctx)
{
    PlantBehavior(
        [](const int id)
        {
            return std::make_pair(
                std::make_unique<Dandelion>(id),
                std::make_unique<DandelionBehavior>()
            );
        }
    ).behave(ctx);
}

std::string DandelionBehavior::getName() const
{
    return "DandelionBehavior";
}
