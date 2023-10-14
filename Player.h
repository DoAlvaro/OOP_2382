#ifndef Player_h
#define Player_h
#define MIN_CHAR 0
#define MAX_HEALTH 1000
#define MAX_POWER 100
#define MAX_ARMOR 100
#define MAX_MONEY 10000
#define MAX_SCORE 1000
#include "Characteristic/Money.h" // 1
#include "Characteristic/Score.h" // 1
#include "Item/Weapon.h"
#include "Item/Item.h"
#include "Move/MoveManager.h"

class Player
{
    Health default_health = Health(MIN_CHAR,MAX_HEALTH,10);
    Power default_power = Power(MIN_CHAR,MAX_POWER,0);
    Armor default_armor = Armor(MIN_CHAR,MAX_ARMOR,0);
    Money default_money = Money(MIN_CHAR,MAX_MONEY,600);
    Score default_score = Score(MIN_CHAR,MAX_SCORE,0);
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
#endif