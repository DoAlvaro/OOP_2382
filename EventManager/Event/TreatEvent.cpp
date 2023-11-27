#include "TreatEvent.h"
#include "../EventManager.h"
#include "../../Player.h"
TreatEvent::TreatEvent(int heal){
    this->heal = heal;
}
TreatEvent* TreatEvent::clone() const{
    return new TreatEvent(*this);
}
void TreatEvent::start(MoveManager& playerControl){
    Player& player = playerControl.getPlayer();
    player.health().setValue(player.health().getValue() + this->heal);
    player.health().isDead();
}