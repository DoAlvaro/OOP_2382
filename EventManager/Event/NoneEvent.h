#ifndef NoneEvent_h
#define NoneEvent_h
#include "Event.h"
class NoneEvent: public Event{
    public:
        NoneEvent();
        NoneEvent* clone() const override;
        void start(MoveManager& playerControl);
};

#endif