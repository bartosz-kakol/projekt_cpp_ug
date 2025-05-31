#pragma once

struct ActionContext;

class IBehavior {
public:
    virtual ~IBehavior() = default;

    /// Definiuje zachowanie organizmu gdy nadejdzie jego tura.
    virtual void behave(ActionContext ctx) = 0;
};
