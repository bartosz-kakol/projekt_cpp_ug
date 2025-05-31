#pragma once

#include <iostream>
#include <string>

#include "World/Base/Interfaces/IAction.h"

class ActionBase : public IAction {
public:
    static void log(const ActionContext& ctx, const std::string& message) ;
};
