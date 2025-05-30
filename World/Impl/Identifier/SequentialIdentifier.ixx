export module World.Impl.Identifier.SequentialIdentifier;

import World.Base.Interfaces.IIdentifier;

export class SequentialIdentifier final : public IIdentifier {
    int nextId = 0;

public:
    int next() override
    {
        return nextId++;
    }
};
