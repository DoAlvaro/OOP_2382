#ifndef EXIT_COMMAND_HH
#define EXIT_COMMAND_HH

#include "ICommand.h"

class ExitCommand: public ICommand
{
public:
    void start(GameManager &game) override;
};

#endif
