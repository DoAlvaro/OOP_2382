#ifndef Observable_h
#define Observable_h
#include "IObserver.h"

class Observable
{
public:
    virtual void addObserver(Observer* apObserver) = 0;
    virtual void removeObserver(Observer* observer) = 0;
    virtual void notify(ViewEvent view_event) = 0;
};

#endif