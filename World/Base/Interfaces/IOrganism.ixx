export module World.Base.Interfaces.IOrganism;

import World.Models.Position;

export class IOrganism
{
public:
    virtual ~IOrganism() = default;

    [[nodiscard]] virtual int getPower() const = 0;

    virtual void setPower(int power) = 0;

    [[nodiscard]] virtual int getInitiative() const = 0;

    virtual void setInitiative(int initiative) = 0;

    [[nodiscard]] virtual int getLiveLength() const = 0;

    virtual void setLiveLength(int liveLength) = 0;

    [[nodiscard]] virtual Position getPosition() const = 0;

    virtual void setPosition(Position position) = 0;

    [[nodiscard]] virtual int getPowerToReproduce() const = 0;

    virtual void setPowerToReproduce(int powerToReproduce) = 0;

    [[nodiscard]] virtual char getSign() const = 0;

    virtual void setSign(char spec) = 0;

    [[nodiscard]] virtual int getId() const = 0;
};
