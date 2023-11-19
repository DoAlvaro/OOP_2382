#include "MoveCommand.h"
#include "../Game/GameManager.h"

MoveCommand::MoveCommand(Direction direction): direction{direction}{}

void MoveCommand::start(GameManager &game) 
{
    game.getPlayerManager().move(direction);
}