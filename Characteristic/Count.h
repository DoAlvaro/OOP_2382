#ifndef Count_h
#define Count_h
#include "Characteristic.h"
class Count: public Characteristic
{
    public:
        Count(int min_value,int max_value,int value);
};
#endif