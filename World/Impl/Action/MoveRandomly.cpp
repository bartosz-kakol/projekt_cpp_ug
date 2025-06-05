#include "MoveRandomly.h"

#include <random>
#include <chrono>

#include "World/Models/ActionContext.h"
#include "World/Models/Position.h"

void MoveRandomly::act(const ActionContext ctx)
{
    const std::uint32_t seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 rng(seed);

    const std::vector<Position> newPositions = ctx.world.getVectorOfPositionsAround(ctx.organism->getPosition());

    if (const int numberOfNewPositions = static_cast<int>(newPositions.size()); numberOfNewPositions > 0) {
        std::uniform_int_distribution dist(0, numberOfNewPositions - 1);
        const int randomIndex = dist(rng);

        log(ctx, "Losowy ruch do pozycji: " + newPositions[randomIndex].toString());
        ctx.organism->setPosition(newPositions[randomIndex]);
    }
}

