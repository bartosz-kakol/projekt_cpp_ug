#pragma once

#include "World/Base/Interfaces/IBehavior.h"

class SheepBehavior final : public IBehavior
{
public:
    void behave(ActionContext ctx) override;
};
