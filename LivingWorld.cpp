#include <iostream>
#include "Position.h"
#include "World.h"
#include "AnimalImpl/Sheep.h"

int main()
{
	World world;

	auto sheep = std::make_unique<Sheep>(Position(3, 3));
	world.addOrganism(std::move(sheep));

	// Tura 0
	std::cout << world.toString() << std::endl;

	// Tura 1
	world.makeTurn();
	std::cout << world.toString() << std::endl;

	// Tura 2
	world.makeTurn();
	std::cout << world.toString() << std::endl;

	// Tura 3
	world.makeTurn();
	std::cout << world.toString() << std::endl;

	// world.writeWorld("world.bin");
	// world.readWorld("world.bin");

	return 0;
}
