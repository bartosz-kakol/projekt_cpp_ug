#pragma once
#include "World/Base/ActionBase.h"

class Reproduce final : public ActionBase {
public:
    void act(ActionContext ctx) override;
};
