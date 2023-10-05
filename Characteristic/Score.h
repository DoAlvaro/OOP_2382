#ifndef Score_h
#define Score_h
#include "Characteristic.h"
class Score: public Characteristic
{
    public:
        Score(int min_value,int max_value,int value);
};
#endif