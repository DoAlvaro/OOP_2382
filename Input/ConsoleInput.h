#ifndef ConsoleInput_h
#define ConsoleInput_h
#include <map>
#include <iostream>
#include <fstream>
#include <algorithm>
#include "../Move/Direction.h"
#include <termios.h>
#include "IInput.h"
class ConsoleInput: public IInput
{
    termios default_attr;
public:
    ConsoleInput();

    char _read() override;
};
#endif