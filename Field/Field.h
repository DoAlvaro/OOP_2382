#ifndef Field_h
#define Field_h
#include "Square.h" // 1
#define DEFAULT_START 0
#define DEFAULT_WIDTH 300
#define DEFAULT_HEIGHT 300
#define START_COORDINATE 
#define END_COORDIANTE 

class Field
{
    int height;
    int width;
    Coordinate start;
    Coordinate end;
    Square** field;
    public:
        Field(int height = DEFAULT_HEIGHT, int width = DEFAULT_WIDTH,Coordinate start = Coordinate(DEFAULT_START,DEFAULT_START),Coordinate end = Coordinate(DEFAULT_WIDTH -1,DEFAULT_HEIGHT -1));
        ~Field();
        Field(Field& other);
        Field(Field&& other);
        Square& getSquare(int x, int y);
        Square& getSquare(Coordinate coordinate);
        int getHeight();
        int getWidth();
        Coordinate& getStart();
        bool checkSize(int x,int y);
        bool checkSize(Coordinate coord);
        Coordinate& getEnd();
        Field& operator=(const Field& other);
        Field& operator=(Field &&other);
        
};
#endif