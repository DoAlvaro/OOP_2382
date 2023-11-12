#include "Input.h"
#include <iostream>
#include <ncurses.h>

char Input::read(){
    char sym;
    initscr();
    timeout(30000000);
    sym = getch();
    timeout(0);
    endwin();
    return sym;
}