#ifndef Game_h
#define Game_h
#include "../Move/MoveManager.h"
#include "../Player.h"
#include "../Field/FieldCreator.h"
#include "../Input/Input.h"
#include <ncurses.h>
#include <unistd.h>
#include <termios.h>
#include <fstream>
#include <iostream>
#include <map>
#include <fstream>
#include <algorithm>
class GameManager{
    int level;
    void start_level_1();
    void start_level_2();
    public:
        // restartLevel();
        void controller(MoveManager& playerControl);
        void chooseLevel(int level);
        bool startLevel();
        void startGame();
        bool isWin(MoveManager& playerControl);
        bool isLose(MoveManager& playerControl);
        void endLevel(bool win);
};
#endif