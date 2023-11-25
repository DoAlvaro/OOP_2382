#ifndef Event_h
#define Event_h
#include <iostream>
#include "EnumEvent.h"
class MoveManager;
class Event
{
    public:
        Event() = default;
        virtual Event* clone() const = 0;
        virtual void start(MoveManager& playerControl) = 0;
        virtual EnumEvent type() const = 0;
};

#endif