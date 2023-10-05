#ifndef Coordinate_h
#define Coordinate_h
#include <iostream>
#include "Direction.h"
class MoveManager;
class Square;
class Coordinate
{
    friend MoveManager;
    friend Square;
    int x;
    int y;
    public:
        Coordinate(int x, int y);;
        int getX();
        int getY();
        std::pair<int,int> getPair();
        // void operator=(Coordinate other);
};
#endif