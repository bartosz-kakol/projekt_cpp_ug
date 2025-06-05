#pragma once

#include "World/Base/Interfaces/IBehavior.h"
#include "World/Impl/Action/Reproduce.h"

class PlantBehavior final : public IBehavior {
    ReproductionCreatorFunction creator;

public:
    explicit PlantBehavior(ReproductionCreatorFunction creator);

    void behave(ActionContext ctx) override;

    std::string getName() const override;
};
