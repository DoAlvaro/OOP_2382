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

Player& MoveManager::getPlayer(){
    return this->player;
}
Field& MoveManager::getField(){
    return this->field;
}
bool MoveManager::checkCoord(Coordinate coord){
    int x = coord.getX();
    int y = coord.getY();
    return (x < this->field.getWidth()) && (y < this->field.getHeight()) && (x >= 0 && y >=0);
}


void MoveManager::move(Direction direction){
    
    int x = 0,y = 0;
            switch (direction){
                case Direction::left:
                    player_coordinate.x += 1;
                    x+=1;
                    break;
                case Direction::right:
                    this->player_coordinate.x -= 1;
                    x-=1;
                    break;
                case Direction::down:
                    this->player_coordinate.y += 1;
                    y+=1;
                    break;
                case Direction::up:

                    this->player_coordinate.y -= 1;
                    y-=1;
                    break;
                default:
                    break;
            }
    if (!(this->checkCoord(this->player_coordinate) && this->field.getSquare(this->player_coordinate).getPassable())){
        player_coordinate.x -=x;
        player_coordinate.y -=y;
        std::cout << "Куда это ты собрался..." << '\n';
    }
    else{
        field.getSquare(player_coordinate.x,player_coordinate.y).getEvent()->start(*this);
    }
    
}
void MoveManager::teleport(Coordinate coordinate){
    int x = coordinate.getX();
    int y = coordinate.getY();
    if (!(this->checkCoord(this->player_coordinate) && this->field.getSquare(this->player_coordinate).getPassable())){
            std::cout << "Куда это ты собрался..." << '\n';
        }
        else{
            player_coordinate.x = x;
            player_coordinate.y = y;
            field.getSquare(y,x).getEvent()->start(*this);
        }
}
void MoveManager::FieldView() {
    int w = field.getWidth();
    int h = field.getHeight();
    int x_start = 0;
    int y_start = 0;
    int x_end = 0;
    int y_end = 0;
    if (w <= 10 && h <= 10) {
        x_start = 0;
        y_start = 0;
        x_end = w;
        y_end = h;
    } else {
        int x_center = player_coordinate.getX();
        int y_center = player_coordinate.getY();
        
        if (x_center < 3) { x_start = 0; x_end = 7; }
        else if (x_center >= w-3) { x_start = w-7; x_end = w; }
        else { x_start = x_center - 3; x_end = x_center + 4; }

        if (y_center < 3) { y_start = 0; y_end = 7; }
        else if (y_center >= h-3) { y_start = h-7; y_end = h; }
        else { y_start = y_center - 3; y_end = y_center + 4; }
    }
    int x = player_coordinate.getX();
    int y = player_coordinate.getY();
    for (int i = y_start; i < y_end; i++) {
        for (int j = x_start; j < x_end; j++) {
            if (field.getSquare(j, i).getPassable()) {
                if (x == j && y == i)
                    if (player.health().isDead()){
                        std::cout << "(X-X)";
                    }
                    else{
                        std::cout << "(T-T)";
                    }
                else
                    std::cout << "  .  ";
            } else {
                std::cout << " [#] ";
            }
        }
        std::cout << "\n";
    }
}
