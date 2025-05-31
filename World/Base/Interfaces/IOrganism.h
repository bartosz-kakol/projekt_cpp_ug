#pragma once

#include "World/Models/Position.h"

class IOrganism {
public:
    virtual ~IOrganism() = default;

    virtual int getPower() const = 0;

    virtual void setPower(int power) = 0;

    virtual int getInitiative() const = 0;

    virtual void setInitiative(int initiative) = 0;

    virtual int getLiveLength() const = 0;

    virtual void setLiveLength(int liveLength) = 0;

    virtual Position getPosition() const = 0;

    virtual void setPosition(Position position) = 0;

    virtual int getPowerToReproduce() const = 0;

    virtual void setPowerToReproduce(int powerToReproduce) = 0;

    virtual char getSign() const = 0;

    virtual void setSign(char spec) = 0;

    virtual int getId() const = 0;

    virtual void setId(int id) = 0;
};

