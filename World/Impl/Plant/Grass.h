#pragma once

#include "World/Base/PlantBase.h"

class Grass final : public PlantBase {
public:
    explicit Grass(int id);

    void init() override;
};
