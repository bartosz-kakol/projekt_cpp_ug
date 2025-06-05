#include "PlantBehavior.h"

#include "World/Impl/Action/Reproduce.h"
#include "World/Models/ActionContext.h"

PlantBehavior::PlantBehavior(ReproductionCreatorFunction creator)
    : creator(std::move(creator))
{

}

void PlantBehavior::behave(const ActionContext ctx)
{
    if (ctx.organism->canReproduce())
    {
        Reproduce(creator).act(ctx);
    }
}

std::string PlantBehavior::getName() const
{
    return "PlantBehavior";
}
