#ifndef Event_h
#define Event_h
#include <iostream>
class MoveManager;
class Event
{
    public: 
        virtual Event* clone() const = 0;
        virtual void start(MoveManager& playerControl) = 0;
};

#endif