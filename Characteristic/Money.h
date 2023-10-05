#ifndef Money_h
#define Mony_h
#include "Characteristic.h"
class Money: public Characteristic
{
    public:
        Money(int min_value,int max_value,int value);
};
#endif