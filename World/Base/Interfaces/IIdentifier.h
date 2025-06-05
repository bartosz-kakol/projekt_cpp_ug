#pragma once

class IIdentifier {
public:
    virtual ~IIdentifier() = default;

    virtual int next() = 0;

    virtual void setState(int state) = 0;
    virtual int getState() const = 0;
};

