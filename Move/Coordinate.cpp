#include "Coordinate.h"
Coordinate::Coordinate(int x, int y){
    this->x = x;
    this->y = y;
}
int Coordinate::getX(){
    return this->x;
}
int Coordinate::getY(){
    return this->y;
}
// void Coordinate::operator=(Coordinate other){
//         throw std::invalid_argument("Попытка присваивания координаты прервана\n");
// }
std::pair<int,int> Coordinate::getPair(){
    std::pair pair = std::make_pair(this->x,this->y);
    return pair;
}