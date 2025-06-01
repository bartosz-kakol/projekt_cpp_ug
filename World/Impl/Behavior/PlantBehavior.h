#pragma once
#include "World/Base/Interfaces/IBehavior.h"

class PlantBehavior final : public IBehavior {
public:
    void behave(ActionContext ctx) override;
};
