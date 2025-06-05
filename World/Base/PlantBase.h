#pragma once

#include "World/Base/OrganismBase.h"

class PlantBase : public OrganismBase {
public:
    using OrganismBase::init;

    explicit PlantBase(int id, int birthTurn);
};
