#include "Health.h"
#include <iostream>
Health::Health(int min_value,int max_value,int value): Characteristic(min_value, max_value, value){
    isDead();
}
bool Health::isDead(){
    if (this->value <= this->min_value && this->is_dead == false){
        this->is_dead = true;
        std::cout << "Поздравляю, Вы мертвы! Теперь вы призрак!" << '\n';
    }
    else{
        if (this->value > this->min_value && this->is_dead == true){
        std::cout << "Поздравляю, Вы воскресли!" << '\n';
        this->is_dead = false;
    }
    }
    return is_dead;
}