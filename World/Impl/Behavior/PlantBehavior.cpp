#include "PlantBehavior.h"

#include "World/Impl/Action/Reproduce.h"
#include "World/Models/ActionContext.h"

void PlantBehavior::behave(const ActionContext ctx)
{
    if (ctx.organism->canReproduce())
    {
        Reproduce().act(ctx);
    }
}
