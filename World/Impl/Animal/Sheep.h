#pragma once

#include "World/Base/AnimalBase.h"

class Sheep final : public AnimalBase {
public:
    explicit Sheep(int id, int birthTurn);

    void init() override;
};

