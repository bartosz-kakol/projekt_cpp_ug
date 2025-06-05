#pragma once

#include "World/Base/Interfaces/IBehavior.h"
#include "World/Impl/Action/Reproduce.h"

class AnimalBehavior final : public IBehavior {
    ReproductionCreatorFunction creator;

public:
    explicit AnimalBehavior(ReproductionCreatorFunction creator);

    void behave(ActionContext ctx) override;

    std::string getName() const override;
};
