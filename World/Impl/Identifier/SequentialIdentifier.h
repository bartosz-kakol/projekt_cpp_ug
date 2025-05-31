#pragma once

#include "World/Base/Interfaces/IIdentifier.h"

class SequentialIdentifier final : public IIdentifier {
    int nextId = 0;

public:
    int next() override;
};
