#include "GameObserver.h"


GameObserver::GameObserver(GameManager* game, IView *view) : game(game), view(view)
{
    game->addObserver(this);
    

}

void GameObserver::update(ViewEvent view_event)
{
    std::map<ViewEvent, std::function<void(IView *)>> choose_map = {
        {ViewEvent::ChooseLevel, [](IView *obj)
         {
             return obj->updateChooseLevel();
         }},
         {ViewEvent::InvalidLevel, [](IView *obj)
         {
             return obj->updateInvalidLevel();
         }},
        {ViewEvent::EndGame, [](IView *obj)
         {
             return obj->updateEndGame();
         }},
         {ViewEvent::InitGame, [](IView *obj)
         {
             return obj->update();
         }},
    };
    choose_map[view_event](view);
}