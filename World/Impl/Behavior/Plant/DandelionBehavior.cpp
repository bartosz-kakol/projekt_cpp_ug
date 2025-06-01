#include "DandelionBehavior.h"

#include "World/Impl/Behavior/PlantBehavior.h"
#include "World/Models/ActionContext.h"

void DandelionBehavior::behave(const ActionContext ctx)
{
    PlantBehavior().behave(ctx);
}
