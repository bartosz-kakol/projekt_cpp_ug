#pragma once
#include "Organism.h"

class Plant : public Organism
{
public:
	using Organism::Organism;

	Plant(Position position, int liveLength, int powerToReproduce, char sign);

	void move(int dx, int dy) override;
	void behave(World& world) override;
};

