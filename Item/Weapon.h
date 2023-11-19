#ifndef Weapon_h
#define Weapon_h
#include "../Characteristic/Power.h"
#include <iostream>
class Weapon
{
    int damage;
    std::string name;
    public:
        Weapon(std::string name, int damage, Power& power);
        int getDamage();
        void setDamage(int damage);
        std::string getName();
        void setName(std::string name);
        void use(Power& power);
        // void operator=(Weapon other);
};
#endif