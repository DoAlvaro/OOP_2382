#include "TeleportEvent.h"
#include "../../Player.h"
TeleportEvent::TeleportEvent(Coordinate coord):coord(coord){
    this->type_event = EnumEvent::Teleport;
}
void TeleportEvent::start(MoveManager& playerControl){
    playerControl.teleport(this->coord);
}
TeleportEvent* TeleportEvent::clone() const{
    return new TeleportEvent(*this);
}
EnumEvent TeleportEvent::type() const{
    return this->type_event;
}