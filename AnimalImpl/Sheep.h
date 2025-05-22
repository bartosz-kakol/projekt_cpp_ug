#pragma once
#include "Animal.h"
#include "Behavior.h"

class SheepBehavior final : public Behavior {
public:
    void act(Organism& self, World& world) override;
};

class Sheep final : public Animal {
public:
    explicit Sheep(Position position);
};
