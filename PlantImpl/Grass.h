#pragma once
#include "Plant.h"

class Grass final : public Plant {
public:
    explicit Grass(int id, Position position);
};
