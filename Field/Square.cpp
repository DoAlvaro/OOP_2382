#include "Square.h"
Square::Square(bool passable, Coordinate coordinate):coordinate(coordinate){
    this->passable = passable;
}
void Square::setPassable(bool passable){
    this->passable = passable;
}
bool Square::getPassable(){
    return this->passable;
}
Coordinate Square::getCoordinate(){
    return this->coordinate;
}

// Square::Square(Square& other): coordinate(other.coordinate){
//     this->passable = other.passable;
// }
Square& Square::operator=(const Square& other){
    if (this == &other || coordinate.getX() >= 0){
        return *this;
        }
    this->coordinate = other.coordinate;
    this->passable = other.passable;
    return *this;
};
