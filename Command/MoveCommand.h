#ifndef MOVE_COMMAND_HH
#define MOVE_COMMAND_HH

#include "ICommand.h"
#include "../Move/Direction.h"

class MoveCommand: public ICommand
{
    Direction direction;
public:
    MoveCommand(Direction direction);

    void start(GameManager &game) override;
};

#endif
