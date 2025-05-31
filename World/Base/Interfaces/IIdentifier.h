#pragma once

class IIdentifier {
public:
    virtual ~IIdentifier() = default;

    virtual int next() = 0;
};

