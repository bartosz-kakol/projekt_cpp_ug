#include <iostream>

import World;
import World.Models.Position;
import World.Impl.Identifier.SequentialIdentifier;
import World.Impl.Animal.Sheep;
import World.Impl.Plant.Grass;
import World.Impl.Behavior.SheepBehavior;
import World.Impl.Behavior.DefaultBehavior;

int main()
{
	auto world = World(
		std::make_unique<SequentialIdentifier>(),
		15, 15
	);

	// Organizmy
	world.createOrganism<Sheep, SheepBehavior>(Position(3, 3));
	world.createOrganism<Grass, DefaultBehavior>(Position(0, 1));
	world.createOrganism<Grass, DefaultBehavior>(Position(1, 0));
	world.createOrganism<Grass, DefaultBehavior>(Position(4, 4));
	world.createOrganism<Grass, DefaultBehavior>(Position(3, 2));

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
