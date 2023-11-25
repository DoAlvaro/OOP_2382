#include "TreatEvent.h"
#include "../EventManager.h"
#include "../../Player.h"
TreatEvent::TreatEvent(int heal){
    this->heal = heal;
    this->type_event = EnumEvent::Treat;
}
TreatEvent* TreatEvent::clone() const{
    return new TreatEvent(*this);
}
void TreatEvent::start(MoveManager& playerControl){
    Player& player = playerControl.getPlayer();
    player.health().setValue(player.health().getValue() + this->heal);
    player.health().isDead();
}
EnumEvent TreatEvent::type() const{
    return this->type_event;
}