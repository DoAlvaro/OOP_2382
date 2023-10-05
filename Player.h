#pragma once
#include "Characteristic/Money.h"
#include "Characteristic/Score.h"
#include "Item/Weapon.h"
#include "Item/Item.h"
#include "Move/MoveManager.h"

class Player
{
    Health default_health = Health(0,1000,10);
    Power default_power = Power(0,100,0);
    Armor default_armor = Armor(0,100,0);
    Money default_money = Money(0,10000,600);
    Score default_score = Score(0,1000,0);
    Weapon default_weapon = Weapon("Кулаки",2,default_power);
    Item default_item = Item("Фласка",100,0,0,1);
    public:
        Health& health();
        Power& power();
        Armor& armor();
        Money& money();
        Score& score();
        Weapon& weapon();
        Item& item();
};