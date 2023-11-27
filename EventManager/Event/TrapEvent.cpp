#include "TrapEvent.h"
#include "../../Player.h"
#include "../EventManager.h"
TrapEvent::TrapEvent(int damage){
    this->damage = damage;
}
void TrapEvent::start(MoveManager& playerControl){
    Player& player = playerControl.getPlayer();
    player.health().setValue(player.health().getValue() - this->damage);
    player.health().isDead();
}
TrapEvent* TrapEvent::clone() const{
    return new TrapEvent(*this);
}