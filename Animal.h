#pragma once
#include "Organism.h"

class Animal : public Organism
{
	Position lastPosition;

protected:
	std::unique_ptr<Behavior> behavior;

public:
	using Organism::Organism;

	void move(int dx, int dy) override;
	void behave(World& world) override;

	Position getLastPosition() const;
};

