#pragma once

class Command {
    Command() = default;
    virtual ~Command() = default;

    virtual void execute() = 0;
};
