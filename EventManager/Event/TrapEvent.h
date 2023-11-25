#ifndef TrapEvent_h
#define TrapEvent_h
#define DEFAULT_DAMAGE 100
#include <iostream>
#include "Event.h"
class TrapEvent : public Event{
    int damage;
    EnumEvent type_event;
    public:
        TrapEvent(int damage = DEFAULT_DAMAGE);
        TrapEvent* clone() const override;
        void start(MoveManager& playerControl);
        EnumEvent type() const override;
};

#endif