#include "UILogger.h"

#include <iostream>
#include <__ostream/basic_ostream.h>

UILogger::UILogger(const WorldViewerWindow& window)
    : window(window)
{

}

void UILogger::log(const std::string& message)
{
    std::cout << message << std::endl;
    window.logMessage(message);
}
