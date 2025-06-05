#include "Die.h"

#include "World/Models/ActionContext.h"

void Die::act(const ActionContext ctx)
{
    log(ctx, "Śmierć.");
    ctx.world.removeOrganism(ctx.organism->getId());
}
