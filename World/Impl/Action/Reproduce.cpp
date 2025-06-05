#include "Reproduce.h"

#include <random>
#include <utility>

#include "World/Models/ActionContext.h"

Reproduce::Reproduce(ReproductionCreatorFunction creator)
    : creator(std::move(creator))
{

}

void Reproduce::act(const ActionContext ctx)
{
    const auto& freePositionsAround = ctx.world.getVectorOfFreePositionsAround(ctx.organism->getPosition());

    if (freePositionsAround.empty()) {
        log(ctx, "Nie ma miejsca, nie można się rozmnożyć!");
        return;
    }

    const std::uint32_t seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 rng(seed);
    const int numberOfNewPositions = static_cast<int>(freePositionsAround.size());
    std::uniform_int_distribution dist(0, numberOfNewPositions - 1);
    const int randomIndex = dist(rng);

    log(ctx, "Rozmnażanie się.");

    const auto& id = ctx.world.getIdentifier()->next();
    const auto& birthTurn = ctx.world.getTurn();
    auto [organism, behavior] = creator(id, birthTurn);
    organism->init();
    organism->setPosition(freePositionsAround[randomIndex]);

    ctx.organism->setPower(ctx.organism->getPower() / 2);
    ctx.organism->addChild(organism.get());
    ctx.world.queueOrganism(std::move(organism), std::move(behavior));
}
