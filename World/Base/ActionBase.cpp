#include "ActionBase.h"

#include "World/Impl/Logger/DefaultLogger.h"
#include "World/Models/ActionContext.h"

std::unique_ptr<ILogger> ActionBase::logger = std::make_unique<DefaultLogger>();

void ActionBase::log(const ActionContext& ctx, const std::string& message)
{
    logger->log("[" + ctx.organism->toString() + "] " + message);
}

