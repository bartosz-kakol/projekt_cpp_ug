#include "SequentialIdentifier.h"

int SequentialIdentifier::next() {
    return nextId++;
}

void SequentialIdentifier::setState(const int state)
{
    nextId = state;
}

int SequentialIdentifier::getState() const
{
    return nextId;
}
