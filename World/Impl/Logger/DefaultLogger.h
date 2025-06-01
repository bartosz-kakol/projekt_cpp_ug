#pragma once

#include "World/Base/Interfaces/ILogger.h"

class DefaultLogger final : public ILogger {
    void log(const std::string& message) override;
};
