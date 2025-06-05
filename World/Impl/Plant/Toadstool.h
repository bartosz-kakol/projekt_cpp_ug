#pragma once

#include "World/Base/PlantBase.h"

class Toadstool final : public PlantBase {
public:
    explicit Toadstool(int id);

    void init() override;
};
