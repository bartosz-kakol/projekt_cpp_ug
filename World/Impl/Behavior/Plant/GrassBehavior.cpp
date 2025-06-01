#include "GrassBehavior.h"

#include "World/Impl/Behavior/PlantBehavior.h"
#include "World/Models/ActionContext.h"

void GrassBehavior::behave(const ActionContext ctx)
{
    PlantBehavior().behave(ctx);
}
