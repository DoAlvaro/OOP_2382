#include "Weapon.h"
Weapon::Weapon(std::string name, int damage, Power& power){
            this->name = name;
            this->damage = damage;
            use(power);
        }
int Weapon::getDamage(){return this->damage;}
void Weapon::setDamage(int damage){this->damage = damage;}
std::string Weapon::getName(){return this->name;}
void Weapon::setName(std::string name){this->name = name;}
void Weapon::use(Power& power){power.setValue(this->damage);}
// void Weapon::operator=(Weapon other){
//         std::cout << "Попытка присваивания оружия прервана\n";
// }