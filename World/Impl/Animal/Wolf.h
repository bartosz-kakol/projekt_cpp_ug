#pragma once

#include "World/Base/AnimalBase.h"

class Wolf final : public AnimalBase {
public:
    explicit Wolf(int id, int birthTurn);

    void init() override;
};
