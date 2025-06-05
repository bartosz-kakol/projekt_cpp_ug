#pragma once

#include "World/Base/Interfaces/IBehavior.h"

class NoBehavior final : public IBehavior
{
public:
    void behave(ActionContext ctx) override;

    std::string getName() const override;
};
