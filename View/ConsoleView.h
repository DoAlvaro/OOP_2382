#ifndef ConsoleView_h
#define ConsoleView_h
#include "GameObserver.h"
#include "../Game/GameManager.h"
#include "../EventManager/Event/EnumEvent.h"
#include "../EventManager/Event/TeleportEvent.h"
#include "IView.h"
#include <iostream>
#include <iomanip>
#include <functional>
#include <unordered_map>
#include <typeinfo>


class ConsoleView: public IView
{
    GameManager* game;
    GameObserver* game_observer;
    void viewField();
    void viewPlayer();
    public:
        ConsoleView(GameManager* game);
        ~ConsoleView();
        void update();
        void updateChooseLevel();
        void updateInvalidLevel();
        void updateEndGame();
};


#endif