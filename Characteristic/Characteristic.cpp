#include <iostream>
#include "Characteristic.h"

Characteristic::Characteristic(int min_value,int max_value,int value){
    this->max_value = std::max(min_value,max_value);
    this->min_value = std::min(min_value,max_value);
    setValue(value);
}

void Characteristic::setValue(int val){
    int status = check(val);
    switch(status){
        case 0:
            this->value = val;
            break;
        case -1:
            this->value = this->min_value;
            break;
        case 1:
            this->value = this->max_value;
            break;
    }
}
int Characteristic::getValue(){
    return this->value;
}
int Characteristic::check(int value){
    if (this->min_value > value) return -1;
    if (this->max_value < value) return 1;
    return 0;
}
