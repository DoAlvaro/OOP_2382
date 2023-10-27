#include "Square.h"
Square::Square(Event* event, bool passable, Coordinate coordinate):coordinate(coordinate){
    this->event = event;
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
Event* Square::getEvent(){
    return this->event;
}
Square::Square(const Square &other) : passable{other.passable},
      event{other.event ? other.event->clone() : nullptr},
      coordinate(other.coordinate){}
Square::Square(Square&& other): coordinate(Coordinate(-1,-1)),
                                event(nullptr),
                                passable(true){
    std::swap(coordinate,other.coordinate);
    std::swap(event,other.event);
    std::swap(passable,other.passable);
}
Square::~Square()
{
     if (this->event != nullptr)
        {
        delete event;
    }
}

Square& Square::operator=(const Square& other){
    if (this == &other || coordinate.getX() >= 0){
        return *this;
        }
    Square tmp(other);
    std::swap(passable, tmp.passable);
    std::swap(event, tmp.event);
    std::swap(coordinate,tmp.coordinate);
    return *this;
};
\
Square& Square::operator=(Square &&other)
{
    if (this != &other) {
        std::swap(passable, other.passable);
        std::swap(event, other.event);
        std::swap(coordinate,other.coordinate);
    }
    return *this;
}