#include "MoveRandomly.h"

#include <random>
#include <chrono>

#include "World/Models/ActionContext.h"
#include "World/Models/Position.h"

void MoveRandomly::act(const ActionContext ctx)
{
    // Inicjalizacja generatora liczb losowych
    const std::uint32_t seed = std::chrono::system_clock::now().time_since_epoch().count();

    std::mt19937 rng(seed);

    // Sprawdzenie wolnych pozycji dookoła organizmu
    const std::vector<Position> newPositions = ctx.world.getVectorOfPositionsAround(ctx.organism->getPosition());

    if (const int numberOfNewPositions = static_cast<int>(newPositions.size()); numberOfNewPositions > 0) {
        // Wygenerowanie liczby losowej do zdobycia losowej wolnej pozycji
        std::uniform_int_distribution dist(0, numberOfNewPositions - 1);
        const int randomIndex = dist(rng);

        log(ctx, "Losowy ruch do pozycji: " + newPositions[randomIndex].toString());
        ctx.organism->setPosition(newPositions[randomIndex]);
    }
}

