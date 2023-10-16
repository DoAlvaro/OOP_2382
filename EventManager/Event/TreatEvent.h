#ifndef TreatEvent_h
#define TreatEvent_h
#define DEFAULT_HEAL 100
#include <iostream>
#include "Event.h"
class TreatEvent : public Event{
    int heal;
    public:
        TreatEvent* clone() const override;
        TreatEvent(int heal = DEFAULT_HEAL);
        void start(MoveManager& playerControl);
};

#endif