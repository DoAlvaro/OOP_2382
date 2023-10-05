#ifndef Health_h
#define Health_h
#include "Characteristic.h"
class Health : public Characteristic
{
    bool is_dead = false;
    public:
        Health(int min_value,int max_value,int value);
        bool isDead();
};
#endif