#pragma once

#include "World/Base/Interfaces/IBehavior.h"

class DandelionBehavior final : public IBehavior {
public:
    void behave(ActionContext ctx) override;

    std::string getName() const override;
};
