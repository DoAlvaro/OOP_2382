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
std::pair<int,int> Coordinate::getPair(){
    std::pair pair = std::make_pair(this->x,this->y);
    return pair;
}