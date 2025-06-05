#include "UILogger.h"

UILogger::UILogger(const WorldViewerWindow& window)
    : window(window)
{

}

void UILogger::log(const std::string& message)
{
    if (window.isLoggingEnabled())
    {
        window.logMessage(message);
    }
}
