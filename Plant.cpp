#include "Plant.h"

Plant::Plant(const char sign, const int id, const Position position, const int liveLength, const int powerToReproduce)
	: Organism(sign, id, position, 0, 0, liveLength, powerToReproduce) {}

void Plant::move(int dx, int dy)
{
	// Roślina się nie rusza.
	// Wywołanie move() zgłasza błąd
	throw std::runtime_error("Rośliny nie mogą się ruszać.");
}

void Plant::behave(World& world)
{
	Organism::behave(world);
	// Roślina nie ma specyficznego zachowania.
}
