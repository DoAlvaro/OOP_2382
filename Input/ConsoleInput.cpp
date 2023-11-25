#include "ConsoleInput.h"
#include <iostream>
#include <ncurses.h>
#include <unistd.h>
#include <termios.h>
#include <set>
#include <vector>
#include "../Move/Direction.h"

char ConsoleInput::_read()
{
    termios new_attr = default_attr;
    new_attr.c_lflag &= (~ECHO & ~ICANON);
    tcsetattr(STDIN_FILENO, TCSANOW, &new_attr);
    char key = std::getchar();
    timeout(0);
    tcsetattr(STDIN_FILENO, TCSANOW, &default_attr);
    return key;
} 
ConsoleInput::ConsoleInput()
{
    tcgetattr(STDIN_FILENO, &default_attr);
}