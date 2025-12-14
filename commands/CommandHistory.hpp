#pragma once

#include <QStack>

class Command;

class CommandHistory {
public:
    QStack<Command *> _undo;
    QStack<Command *> _redo;
};
