#include "AnimalBehavior.h"

#include "World/Impl/Action/Eat.h"
#include "World/Impl/Action/MoveRandomly.h"
#include "World/Impl/Action/Reproduce.h"
#include "World/Models/ActionContext.h"

AnimalBehavior::AnimalBehavior(ReproductionCreatorFunction creator)
    : creator(std::move(creator))
{

}

void AnimalBehavior::behave(const ActionContext ctx)
{
    if (ctx.organism->canReproduce())
    {
        Reproduce(creator).act(ctx);
    }

    const auto ourPower = ctx.organism->getPower();
    Eat(
        [ourPower](std::vector<IOrganism*>& organisms) {
            const auto iter = std::remove_if(
                organisms.begin(), organisms.end(),
                [ourPower](const IOrganism* org) {
                    return org->getPower() > ourPower;
                }
            );
            organisms.erase(iter, organisms.end());
        }
    ).act(ctx);

    MoveRandomly().act(ctx);
}

std::string AnimalBehavior::getName() const
{
    return "AnimalBehavior";
}
