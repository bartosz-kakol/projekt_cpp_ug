#pragma once

#include <iostream>
#include <string>

#include "World/Base/Interfaces/ILogger.h"
#include "World/Base/Interfaces/IAction.h"

class ActionBase : public IAction {
public:
    static std::unique_ptr<ILogger> logger;

protected:
    static void log(const ActionContext& ctx, const std::string& message) ;
};
