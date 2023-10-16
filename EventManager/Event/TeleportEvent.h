#ifndef TeleportEvent_h
#define TeleportEvent_h
#include "Event.h"
#include "../../Move/Coordinate.h"
class TeleportEvent: public Event{
    Coordinate coord;
    public:
        TeleportEvent(Coordinate coord);
        TeleportEvent* clone() const override;
        void start(MoveManager& playerControl);
};

#endif