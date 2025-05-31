#include "DefaultBehavior.h"

#include <iostream>

#include "World/Models/ActionContext.h"

void DefaultBehavior::behave(ActionContext ctx)
{
    std::cout << "Domyślne zachowanie" << std::endl;
}
