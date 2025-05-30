export module World.Base.Interfaces.IIdentifier;

export class IIdentifier {
public:
    virtual ~IIdentifier() = default;

    virtual int next() = 0;
};

