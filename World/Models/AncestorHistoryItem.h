#pragma once

#include "Serializer/Base/Interfaces/ISerializable.h"
#include "Serializer/Variant.h"

class AncestorHistoryItem final : public ISerializable
{
public:
    AncestorHistoryItem(int births = 0, int deaths = 0);

    int births;
    int deaths;

    void serialize(Variant& v) override;
    void deserialize(Variant& source) override;
};
