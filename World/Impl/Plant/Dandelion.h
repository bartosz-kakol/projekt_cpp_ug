#pragma once
#include "World/Base/PlantBase.h"

class Dandelion final : public PlantBase {
public:
    explicit Dandelion(int id, int birthTurn);

    void init() override;
};
