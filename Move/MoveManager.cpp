#include "MoveManager.h"
#include "../Player.h"


Coordinate& MoveManager::coordinate(){
    return this->player_coordinate;
}


MoveManager::MoveManager(Player& player,Field& field) : player(player), field(field),player_coordinate(field.getStart()){
    if (!(checkCoord(player_coordinate)  && checkCoord(field.getEnd()))){
        throw std::invalid_argument("нельзя встать сюда\n");
    }
}


bool MoveManager::checkCoord(Coordinate coord){
    int x = coord.getX();
    int y = coord.getY();
    return (x < this->field.getWidth()) && (y < this->field.getHeight()) && (x >= 0 && y >=0);
}


void MoveManager::move(Direction direction){
    int x = 0,y = 0;
            switch (direction){
                case Direction::right:
                    player_coordinate.x += 1;
                    x+=1;
                    break;
                case Direction::left:
                    this->player_coordinate.x -= 1;
                    x-=1;
                    break;
                case Direction::up:
                    this->player_coordinate.y += 1;
                    y+=1;
                    break;
                case Direction::down:
                    this->player_coordinate.y -= 1;
                    y-=1;
                    break;
            }
    if (!(this->checkCoord(this->player_coordinate) && this->field.getSquare(this->player_coordinate).getPassable())){
        player_coordinate.x -=x;
        player_coordinate.y -=y;
        std::cout << "Куда это ты собрался..." << '\n';
    }
}
