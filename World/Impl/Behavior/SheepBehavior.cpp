#include "SheepBehavior.h"

#include "World/Impl/Action/Eat.h"
#include "World/Impl/Action/MoveRandomly.h"
#include "World/Models/ActionContext.h"

void SheepBehavior::behave(const ActionContext ctx) {
    MoveRandomly().act(ctx);
    Eat(
        [](std::vector<IOrganism*>& organisms) {
            const auto iter = std::remove_if(
                organisms.begin(), organisms.end(),
                [](const IOrganism* org) {
                    return org->getSign() != 'T';
                }
            );
            organisms.erase(iter, organisms.end());
        }
    ).act(ctx);
}
