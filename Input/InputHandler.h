#ifndef INPUT_HANDLER_HH
#define INPUT_HANDLER_HH

#include <map>
#include <memory>

class ICommand;
class IConfigReader;
class GameManager;

class InputHandler
{
    std::map<char, std::shared_ptr<ICommand>> commandTable;

public:
    InputHandler(IConfigReader &config_reader);

    void handleInput(char key, GameManager &game);

    std::map<char, std::shared_ptr<ICommand>>& getTable();
};

#endif
