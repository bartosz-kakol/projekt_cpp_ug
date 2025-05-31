#pragma once

#include "Sheep.h"
#include "World/Base/AnimalBase.h"

class Sheep final : public AnimalBase {
public:
    explicit Sheep(int id);

    void init() override;
};

