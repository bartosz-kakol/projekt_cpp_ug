#pragma once

#include "World/Base/ActionBase.h"

class Die final : public ActionBase {
public:
    void act(ActionContext ctx) override;
};
