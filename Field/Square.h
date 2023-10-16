#ifndef Square_h
#define Square_h
#include "../Move/Coordinate.h"
// #include "FieldCreator.h"
#include "../EventManager/Event/Event.h"
class Event;
class FieldCreator;
class Square
{
    friend FieldCreator;
    bool passable;
    Coordinate coordinate;
    Event* event;
    public:
        
        Square(Event* event = nullptr, bool passable = true,Coordinate coordinate = Coordinate(-1,-1));
        Square(const Square& other);
        Square(Square&& other);
        ~Square();
        void setPassable(bool passable);
        bool getPassable();
        Event* getEvent();
        Coordinate getCoordinate();
        Square& operator=(const Square& other);
        Square& operator=(Square &&other);
};
#endif