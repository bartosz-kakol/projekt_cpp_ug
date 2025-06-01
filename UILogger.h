#pragma once

#include "UI/WorldViewerWindow.h"
#include "World/Base/Interfaces/ILogger.h"

class UILogger final : public ILogger {
    const WorldViewerWindow& window;

public:
    explicit UILogger(const WorldViewerWindow& window);

    void log(const std::string& message) override;
};
