#ifndef Power_h
#define Power_h
#include "Characteristic.h"
class Power: public Characteristic
{
    public:
        Power(int min_value,int max_value,int value);
};
#endif