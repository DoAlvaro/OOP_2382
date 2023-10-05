#include <iostream>
#include "Player.h"
Health& Player::health(){
    return this->default_health;
}
Power& Player::power(){
    return this->default_power;
}
Armor& Player::armor(){
    return this->default_armor;
}
Money& Player::money(){
    return this->default_money;
}
Score& Player::score(){
    return this->default_score;
}
Weapon& Player::weapon(){
    return this->default_weapon;
}
Item& Player::item(){
    return this->default_item;
}
