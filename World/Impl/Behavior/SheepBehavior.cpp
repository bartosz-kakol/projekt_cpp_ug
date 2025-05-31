#include "SheepBehavior.h"

#include <iostream>

#include "World/Impl/Action/MoveRandomly.h"
#include "World/Models/ActionContext.h"

void SheepBehavior::behave(const ActionContext ctx) {
    std::cout << "Losowy ruch" << std::endl;
    MoveRandomly().act(ctx);

    std::cout << "Jedzenie trawy" << std::endl;
}
