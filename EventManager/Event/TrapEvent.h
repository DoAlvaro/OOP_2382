#ifndef TrapEvent_h
#define TrapEvent_h
#define DEFAULT_DAMAGE 100
#include <iostream>
#include "Event.h"
class TrapEvent : Event{
    int damage;
    public:
        TrapEvent(int damage = DEFAULT_DAMAGE);
        TrapEvent* clone() const override;
        void start(MoveManager& playerControl);
};

#endif