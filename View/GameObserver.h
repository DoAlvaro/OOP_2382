#ifndef GameObserver_h
#define GameObserve_h

#include "IView.h"
#include "IObserver.h"
#include <iostream>
#include "../Game/GameManager.h"
#include "EnumView.h"

class GameObserver: public Observer
{
    GameManager* game;
    IView* view;
    public:
        GameObserver(GameManager* game, IView* view);
        void update(ViewEvent view_event) override;

};


#endif