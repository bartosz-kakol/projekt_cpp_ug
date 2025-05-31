#pragma once

#include "World/Base/ActionBase.h"
#include "World/Models/ActionContext.h"

class Eat final : public ActionBase {
    const std::function<void(std::vector<IOrganism*>&)>& filter;

public:
    explicit Eat(const std::function<void(std::vector<IOrganism*>&)>& filter);

    void act(ActionContext ctx) override;
};
