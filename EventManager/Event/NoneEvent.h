#ifndef NoneEvent_h
#define NoneEvent_h
#include "Event.h"
class NoneEvent: public Event{
    EnumEvent type_event;
    public:
        NoneEvent();
        NoneEvent* clone() const override;
        void start(MoveManager& playerControl);
        EnumEvent type() const override;
};

#endif