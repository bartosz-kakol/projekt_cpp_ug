#pragma once

#include "World/Base/Interfaces/IBehavior.h"

class WolfBehavior final : public IBehavior {
public:
    void behave(ActionContext ctx) override;
};
