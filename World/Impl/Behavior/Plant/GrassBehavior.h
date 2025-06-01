#pragma once

#include "World/Base/Interfaces/IBehavior.h"

class GrassBehavior final : public IBehavior {
public:
    void behave(ActionContext ctx) override;
};
