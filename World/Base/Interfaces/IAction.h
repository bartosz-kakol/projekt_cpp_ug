#pragma once


struct ActionContext;

class IAction {
public:
    virtual ~IAction() = default;

    virtual void act(ActionContext ctx) = 0;
};

