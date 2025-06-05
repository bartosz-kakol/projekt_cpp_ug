#include "AncestorHistoryItem.h"

AncestorHistoryItem::AncestorHistoryItem(const int id, const int births, const int deaths)
    : id(id), births(births), deaths(deaths)
{

}

void AncestorHistoryItem::serialize(Variant& v)
{
    v.addChild("id", Variant::fromValue(id));
    v.addChild("births", Variant::fromValue(births));
    v.addChild("deaths", Variant::fromValue(deaths));
}

void AncestorHistoryItem::deserialize(Variant& source)
{
    id = source.getChild("id").getValueAs<int>();
    births = source.getChild("births").getValueAs<int>();
    deaths = source.getChild("deaths").getValueAs<int>();
}
