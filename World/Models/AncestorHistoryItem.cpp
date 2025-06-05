#include "AncestorHistoryItem.h"

AncestorHistoryItem::AncestorHistoryItem(const int births, const int deaths)
    : births(births), deaths(deaths)
{

}

void AncestorHistoryItem::serialize(Variant& v)
{
    v.addChild("births", Variant::fromValue(births));
    v.addChild("deaths", Variant::fromValue(deaths));
}

void AncestorHistoryItem::deserialize(Variant& source)
{
    births = source.getChild("births").getValueAs<int>();
    deaths = source.getChild("deaths").getValueAs<int>();
}
