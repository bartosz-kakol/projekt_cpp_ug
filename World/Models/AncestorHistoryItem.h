#pragma once

#include "Serializer/Base/Interfaces/ISerializable.h"
#include "Serializer/Variant.h"

class AncestorHistoryItem final : public ISerializable
{
public:
    explicit AncestorHistoryItem(int id = -1, int births = -1, int deaths = -1);

    int id;
    int births;
    int deaths;

    void serialize(Variant& v) override;
    void deserialize(Variant& source) override;
};
