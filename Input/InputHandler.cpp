#include "InputHandler.h"
#include "IConfigReader.h"
#include "../Command/ICommand.h"
#include <iostream>

InputHandler::InputHandler(IConfigReader &config_reader)
{
    commandTable = config_reader.readConfig();
}

void InputHandler::handleInput(char key, GameManager& game)
{
    key = std::toupper(key);
    if (commandTable.count(key) != 0)
        commandTable.at(key)->start(game);
}
std::map<char, std::shared_ptr<ICommand>>& InputHandler::getTable(){
    return this->commandTable;
}