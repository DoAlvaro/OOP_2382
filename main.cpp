#include <iostream> // 1
// #include "Player.h" // 1
// #include "Field/Field.h"
// #include "EventManager/Event/Event.h"
// #include "EventManager/Event/NoneEvent.h"
// #include "EventManager/Event/TrapEvent.h"
// #include "EventManager/Event/TreatEvent.h"
// #include "EventManager/Event/TeleportEvent.h"
// #include "Field/FieldCreator.h"
#include "Game/GameManager.h"
#include "Input/FileConfigReader.h"
#include "Input/ConsoleInput.h"
#include "View/ConsoleView.h"
int main()
{
    ConsoleInput input_reader;
    FileConfigReader config_reader("Input/CONFIG");
    GameManager game(config_reader, input_reader);
    ConsoleView view(&game);
    game.startGame();
    return 0;
}