#include "Reproduce.h"

#include "World/Models/ActionContext.h"

void Reproduce::act(const ActionContext ctx)
{
    const auto& freePositionsAround = ctx.world.getVectorOfFreePositionsAround(ctx.organism->getPosition());

    if (freePositionsAround.empty()) {
        log(ctx, "Nie ma miejsca, nie można się rozmnożyć!");
        return;
    }

    log(ctx, "Rozmnażanie się.");

    ctx.organism->setPower(ctx.organism->getPower() / 2);
}
