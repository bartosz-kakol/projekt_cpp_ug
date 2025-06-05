#pragma once

#include <string>

struct ActionContext;

class IBehavior {
public:
    virtual ~IBehavior() = default;

    /// Definiuje zachowanie organizmu gdy nadejdzie jego tura.
    virtual void behave(ActionContext ctx) = 0;

    virtual std::string getName() const = 0;
};
