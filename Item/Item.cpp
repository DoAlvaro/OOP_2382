#include "Item.h"
Item::Item(std::string name,int health, int power, int armor, int count): health(Health(0,250,health)), power(Power(0,50,power)), armor(Armor(0,50,armor)),count(Count(0,16,count)){
    this->name = name;
}
std::string Item::getName(){return this->name;}
void Item::setName(std::string name){this->name = name;}