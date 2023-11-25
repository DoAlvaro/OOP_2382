#ifndef TeleportEvent_h
#define TeleportEvent_h
#include "Event.h"
#include "../../Move/Coordinate.h"
#include "EnumEvent.h"
class TeleportEvent: public Event{
    Coordinate coord;
    EnumEvent type_event;
    public:
        TeleportEvent(Coordinate coord);
        TeleportEvent* clone() const override;
        void start(MoveManager& playerControl);
        EnumEvent type() const override;
};

#endif