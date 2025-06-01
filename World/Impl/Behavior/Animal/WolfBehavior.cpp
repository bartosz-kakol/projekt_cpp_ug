#include "WolfBehavior.h"

#include "World/Impl/Behavior/AnimalBehavior.h"
#include "World/Models/ActionContext.h"

void WolfBehavior::behave(const ActionContext ctx)
{
    AnimalBehavior().behave(ctx);
}
