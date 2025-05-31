#include <iostream>
#include <random>
#include <chrono>

#include "World/Creator.h"
#include "World/World.h"
#include "World/Impl/Animal/Sheep.h"
#include "World/Impl/Plant/Grass.h"
#include "World/Impl/Behavior/SheepBehavior.h"
#include "World/Impl/Behavior/DefaultBehavior.h"
#include "World/Impl/Identifier/SequentialIdentifier.h"

int main()
{
	auto world = World(15, 15);
	auto creator = Creator<SequentialIdentifier>(world);

	// Ustawienie świata
	creator.createOrganism<Sheep, SheepBehavior>(
		[](Sheep* organism, [[maybe_unused]] SheepBehavior* behavior) {
			organism->setPosition(Position(7, 8));
		}
	);

	for (int i = 0; i < 20; ++i)
	{
		const std::uint32_t seed = std::chrono::system_clock::now().time_since_epoch().count();
		std::mt19937 rng(seed);
		std::uniform_int_distribution distX(0, world.getWidth()- 1);
		std::uniform_int_distribution distY(0, world.getHeight() - 1);

		creator.createOrganism<Grass, DefaultBehavior>(
			[&rng, &distX, &distY](Grass* organism, [[maybe_unused]] DefaultBehavior* behavior)
			{
				organism->setPosition(Position(distX(rng), distY(rng)));
			}
		);
	}

	while (true)
	{
		std::cout << world.toString() << std::endl;

		std::cout << std::endl;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		world.makeTurn();
	}

	// world.writeWorld("world.bin");
	// world.readWorld("world.bin");

	return 0;
}
