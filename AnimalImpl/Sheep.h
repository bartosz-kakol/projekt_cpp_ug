#pragma once
#include "Animal.h"
#include "Behavior.h"

class SheepBehavior final : public Behavior {
public:
    void behave(Organism& self, World& world) override;
};

class Sheep final : public Animal {
public:
    Sheep(int id, Position position);
};
