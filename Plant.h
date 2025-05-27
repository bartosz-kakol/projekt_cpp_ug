#pragma once
#include "Organism.h"

class Plant : public Organism
{
public:
	using Organism::Organism;

	Plant(char sign, int id, Position position, int liveLength, int powerToReproduce);

	void move(int dx, int dy) override;
	void behave(World& world) override;
};

