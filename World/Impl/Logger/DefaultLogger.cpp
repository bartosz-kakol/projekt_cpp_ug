#include "DefaultLogger.h"

#include <iostream>

void DefaultLogger::log(const std::string& message)
{
    std::cout << message << std::endl;
}
