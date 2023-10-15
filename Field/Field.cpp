#include "Field.h"
#include "../EventManager/Event/NoneEvent.h"
#define MAX_SIZE 300
#define MIN_SIZE 3



Field::Field(int height, int width, Coordinate start, Coordinate end) : start(start), end(end)
{
    this->width = width;
    this->height = height;
    if (checkSize(height,width)){throw std::invalid_argument("Поле недопустимого размера");}
    Square** array;
    array = new Square*[height];
    for (int x = 0; x < height; x++){
        array[x] = new Square[width];
        for (int y = 0; y < width; y++){
            NoneEvent *event = new NoneEvent;
            array[x][y] = Square(event,true, Coordinate(x,y));
        }
    }
    this->field = array;
}
Field::Field(Field& other): start(other.start), end(other.end){
    width = other.width;
    height = other.height;
    field = new Square*[height];
    for (int i = 0; i < height; ++i) {
        field[i] = new Square[width];
        for (int j = 0; j < width; ++j) {
            field[i][j] = other.field[i][j];
        }
    }
}
Field::Field(Field&& other): width(other.width),
    height(other.height),
    start(std::move(other.start)),
    end(std::move(other.end)),
    field(other.field)
{
    other.field = nullptr;
}

Field::~Field()
{   
    if (this->field != nullptr)
        {
        for (int i = 0; i < height; i ++)
        {
            delete [] field[i];
        }
        
        delete [] field;
    }    
}
Square& Field::getSquare(int x, int y){
    return this->field[x][y];
}

Square& Field::getSquare(Coordinate coordinate){
    return this->field[coordinate.getX()][coordinate.getY()];
}

Coordinate& Field::getStart(){return this->start;}
Coordinate& Field::getEnd(){return this->end;}

int Field::getHeight(){return this->height;}
int Field::getWidth(){return this->width;}
bool Field::checkSize(int x,int y){
    return (!(x >= MIN_SIZE && x<=MAX_SIZE && y >= MIN_SIZE && y<= MAX_SIZE));
}
bool Field::checkSize(Coordinate coord){
    int x = coord.getX();
    int y = coord.getY();
    return (!(x >= MIN_SIZE && x<=MAX_SIZE && y >= MIN_SIZE && y<= MAX_SIZE));
}
Field& Field::operator=(const Field& other){
    if (this == &other){
        return *this;
    }
    start = other.start;
    end = other.start;
    width = other.width;
    height = other.height;
    field = new Square*[height];
    for (int i = 0; i < height; ++i) {
        field[i] = new Square[width];
    }
    
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j){
            field[i][j] = other.field[i][j];
            }
        }
    return *this;
}
Field& Field::operator=(Field &&other){
    if (this == &other){
        return *this;
    }
    std::swap(start, other.start);
    std::swap(end, other.start);
    std::swap(width, other.width);
    std::swap(height, other.height);
    field = new Square*[height];
    for (int i = 0; i < height; ++i) {
        field[i] = new Square[width];
    }
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j){
            field[i][j] = other.field[i][j];
            }
        }
    return *this;
}
