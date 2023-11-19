#ifndef GameManager_h
#define GameManager_h
#include "../Move/MoveManager.h"
#include "../Player.h"
#include "../Field/FieldCreator.h"
#include "../Input/ConsoleInput.h"
#include <ncurses.h>
#include <unistd.h>
#include <termios.h>
#include <fstream>
#include <iostream>
#include <map>
#include <fstream>
#include <algorithm>
#include "../Input/IConfigReader.h"
#include "../Input/IInput.h"
#include "../Input/InputHandler.h"

class GameManager{
    int level;
    Player player;
    Field field;
    MoveManager playerControl;
    IConfigReader& configReader;
    IInput& input;
    InputHandler config;
    void generate_level_1();
    void generate_level_2();
    public:
        GameManager(IConfigReader &configgReader, ConsoleInput inputReader);
        MoveManager& getPlayerManager();
        void startLevel();
        void chooseLevel(int level);
        bool generateLevel();
        void startGame();
        bool isWin(MoveManager& playerControl);
        bool isLose(MoveManager& playerControl);
        void endLevel(bool win);
};
#endif