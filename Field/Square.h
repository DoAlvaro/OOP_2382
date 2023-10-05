#ifndef Square_h
#define Square_h
#include "../Move/Coordinate.h"
class Square
{
    bool passable;
    Coordinate coordinate;
    public:
        Square(bool passable = true,Coordinate coordinate = Coordinate(-1,-1));
        Square(Square& other);
        void setPassable(bool passable);
        bool getPassable();
        Coordinate& getCoordinate();
        Square& operator=(const Square& other);
};
#endif