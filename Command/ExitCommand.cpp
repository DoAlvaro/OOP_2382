#include "ExitCommand.h"

void ExitCommand::start(GameManager &game) 
{
    game.endLevel(false);
}