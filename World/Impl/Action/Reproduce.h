#pragma once

#include "World/Base/ActionBase.h"
#include "World/Base/OrganismBase.h"
#include "World/Base/Interfaces/IBehavior.h"

typedef std::function<std::pair<std::unique_ptr<OrganismBase>, std::unique_ptr<IBehavior>>(int)> ReproductionCreatorFunction;

class Reproduce final : public ActionBase {
    ReproductionCreatorFunction creator;

public:
    explicit Reproduce(ReproductionCreatorFunction creator);

    void act(ActionContext ctx) override;
};
