#include "TeleportEvent.h"
#include "../../Player.h"
TeleportEvent::TeleportEvent(Coordinate coord):coord(coord){}
void TeleportEvent::start(MoveManager& playerControl){
    playerControl.teleport(this->coord);
}
TeleportEvent* TeleportEvent::clone() const{
    return new TeleportEvent(*this);
}