#ifndef Item_h
#define Item_h
#include <iostream>
#include "../Characteristic/Power.h"
#include "../Characteristic/Health.h"
#include "../Characteristic/Armor.h"
#include "../Characteristic/Count.h"
class Item
{
    std::string name;
    Health health;
    Power power;
    Armor armor;
    Count count;
    public:
        Item(std::string name,int health=0, int power=0, int armor=0, int count=0);
        std::string getName();
        void setName(std::string name);
};
#endif