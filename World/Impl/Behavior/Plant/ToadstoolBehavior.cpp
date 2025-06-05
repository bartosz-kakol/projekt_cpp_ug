#include "ToadstoolBehavior.h"

#include "World/Impl/Action/Die.h"
#include "World/Impl/Action/Eat.h"
#include "World/Impl/Behavior/PlantBehavior.h"
#include "World/Impl/Plant/Toadstool.h"
#include "World/Models/ActionContext.h"

void ToadstoolBehavior::behave(const ActionContext ctx)
{
    PlantBehavior(
        [](const int id)
        {
            return std::make_pair(
                std::make_unique<Toadstool>(id),
                std::make_unique<ToadstoolBehavior>()
            );
        }
    ).behave(ctx);

    const auto& ourId = ctx.organism->getId();
    const auto& ourPosition = ctx.organism->getPosition();
    const auto& ourPower = ctx.organism->getPower();
    auto organismsHere = ctx.world.getOrganismsFromPosition(ourPosition.getX(), ourPosition.getY());

    const auto iter = std::remove_if(
        organismsHere.begin(), organismsHere.end(),
        [ourId](const IOrganism* org)
        {
            return org->getId() == ourId;
        }
    );
    organismsHere.erase(iter, organismsHere.end());

    const auto shouldDie = !organismsHere.empty() && std::any_of(
        organismsHere.begin(), organismsHere.end(),
        [ourPower](const IOrganism* org) {
            return org->getPower() >= ourPower;
        }
    );

    Eat().act(ctx);

    if (shouldDie)
    {
        Die().act(ctx);
    }
}

std::string ToadstoolBehavior::getName() const
{
    return "ToadstoolBehavior";
}
