module;

#include <chrono>
#include <random>

export module World.Impl.Action.MoveRandomly;

import World.Base.Interfaces.IAction;
import World.Base.Interfaces.IOrganism;
import World.Base.Interfaces.IWorld;
import World.Models.Position;

export class MoveRandomly final : public IAction {
public:
    void act(IOrganism& self, IWorld& world) override
    {
        // Inicjalizacja generatora liczb losowych
        const std::uint32_t seed = std::chrono::system_clock::now().time_since_epoch().count();

        std::mt19937 rng(seed);

        // Sprawdzenie wolnych pozycji dookoła organizmu
        const std::vector<Position> newPositions = world.getVectorOfFreePositionsAround(self.getPosition());

        if (const int numberOfNewPositions = static_cast<int>(newPositions.size()); numberOfNewPositions > 0) {
            // Wygenerowanie liczby losowej do zdobycia losowej wolnej pozycji
            std::uniform_int_distribution dist(0, numberOfNewPositions - 1);
            const int randomIndex = dist(rng);

            self.setPosition(newPositions[randomIndex]);
        }
    }
};
