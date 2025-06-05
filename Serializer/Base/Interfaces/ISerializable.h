#pragma once

#include "Serializer/Variant.h"

class ISerializable
{
public:
    virtual ~ISerializable() = default;

    virtual void serialize(Variant& v) = 0;

    virtual void deserialize(Variant& source) = 0;
};
