#include "NoneEvent.h"
#include "../../Player.h"
NoneEvent::NoneEvent(){
    this->type_event = EnumEvent::None;
}
void NoneEvent::start(MoveManager& playerControl){
    Player& player = playerControl.getPlayer();
    player.score().setValue(player.score().getValue() + 1);
}
NoneEvent* NoneEvent::clone() const{
    return new NoneEvent(*this);
}
EnumEvent NoneEvent::type() const{
    return this->type_event;
}