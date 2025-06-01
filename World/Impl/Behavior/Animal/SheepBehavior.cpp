#include "SheepBehavior.h"

#include "World/Impl/Behavior/AnimalBehavior.h"
#include "World/Models/ActionContext.h"

void SheepBehavior::behave(const ActionContext ctx)
{
    AnimalBehavior().behave(ctx);
}
