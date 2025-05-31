#include "ActionBase.h"

#include "World/Models/ActionContext.h"

void ActionBase::log(const ActionContext& ctx, const std::string& message)
{
    std::cout << "[" << ctx.organism->toString() << "] " << message << std::endl;
}

