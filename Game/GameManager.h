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
#include "../View/EnumView.h"
#include "../View/IObserver.h"
#include "../View/IObservable.h"

class GameManager : Observable{
    int level;
    Player player;
    Field field;
    MoveManager playerControl;
    IConfigReader& configReader;
    IInput& input;
    InputHandler config;
    std::vector<Observer*> observers;
    void generate_level_1();
    void generate_level_2();
    bool win;
    public:
        GameManager(IConfigReader &configgReader, ConsoleInput inputReader);
        MoveManager& getPlayerManager();
        bool getWin();
        void startLevel();
        void chooseLevel(int level);
        bool generateLevel();
        void startGame();
        bool isWin(MoveManager& playerControl);
        bool isLose(MoveManager& playerControl);
        void endLevel(bool win);

        void addObserver(Observer* apObserver) override;
        void removeObserver(Observer* observer) override;
        void notify(ViewEvent view_event) override;
};
#endif