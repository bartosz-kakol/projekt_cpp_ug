#include "Plant.h"

Plant::Plant(const Position position, const int liveLength, const int powerToReproduce, const char sign)
	: Organism(0, 0, liveLength, powerToReproduce, position, sign) {}

void Plant::move(int dx, int dy)
{
	// Roślina się nie rusza.
	// Wywołanie move() zgłasza błąd
	throw std::runtime_error("Rośliny nie mogą się ruszać.");
}

void Plant::behave(World& world)
{
	// Roślina nie ma zachowania.
}
