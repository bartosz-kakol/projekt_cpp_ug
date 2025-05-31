#pragma once

#include "World/Base/ActionBase.h"

class MoveRandomly final : public ActionBase {
public:
    void act(ActionContext ctx) override;
};

