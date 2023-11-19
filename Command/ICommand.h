#ifndef I_COMMAND_HH
#define I_COMMAND_HH
#include "../Game/GameManager.h"

class ICommand
{
public:
    virtual void start(GameManager &game) = 0;
};

#endif
