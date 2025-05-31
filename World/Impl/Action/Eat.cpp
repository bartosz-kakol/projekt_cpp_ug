#include "Eat.h"

#include <iostream>

#include "World/Models/ActionContext.h"

Eat::Eat(const std::function<void(std::vector<IOrganism*>&)>& filter)
    : filter(filter)
{

}

void Eat::act(const ActionContext ctx)
{
    // Pobieramy organizmy w tej samej komórce co organizm wykonujący akcję
    auto organismsHere = ctx.world.getOrganismsFromPosition(
        ctx.organism->getPosition().getX(),
        ctx.organism->getPosition().getY()
    );

    // Usuwamy siebie z tej listy
    const auto ourId = ctx.organism->getId();
    const auto iter = std::remove_if(
        organismsHere.begin(), organismsHere.end(),
        [&ourId](const IOrganism* org)
        {
            return org->getId() == ourId;
        }
    );
    organismsHere.erase(iter, organismsHere.end());

    // Przepuszczamy listę organizmów przez filtr
    filter(organismsHere);

    // Usuwamy (albo "jemy") wszystkie pozostałe organizmy w liście
    for (const auto& org : organismsHere) {
        log(ctx, "Zjedzono " + org->toString());
        ctx.world.removeOrganism(org->getId());
    }
}
