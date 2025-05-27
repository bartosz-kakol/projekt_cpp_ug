#pragma once
#include "Action.h"


class MoveRandomly final : public Action {
public:
    void act(Organism& self, World& world) override;
};
