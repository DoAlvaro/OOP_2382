#include "NoneEvent.h"
#include "../../Player.h"
void NoneEvent::start(MoveManager& playerControl){
    Player& player = playerControl.getPlayer();
    player.score().setValue(player.score().getValue() + 1);
}
NoneEvent* NoneEvent::clone() const{
    return new NoneEvent(*this);
}