#pragma once

#include "World/Base/Interfaces/IBehavior.h"

class DefaultBehavior final : public IBehavior
{
    void behave(ActionContext ctx) override;
};
