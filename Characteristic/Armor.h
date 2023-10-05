#ifndef Armor_h
#define Armor_h
#include "Characteristic.h"
class Armor: public Characteristic
{
    public:
        Armor(int min_value,int max_value,int value);
};
#endif