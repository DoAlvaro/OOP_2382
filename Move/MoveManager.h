#ifndef MoveManager_h
#define MoveManager_h
#include "Direction.h"
#include "Coordinate.h"
#include "../Player.h"
#include "../Field/Field.h"
class Player;
class MoveManager{
    Player& player;
    Field& field;
    Coordinate player_coordinate;
    bool checkCoord(Coordinate coord);
    public:
        Player& getPlayer();
        Field& getField();
        explicit MoveManager(Player& player, Field& field) ;
        void move(Direction direction);
        void teleport(Coordinate coordinate);
        Coordinate& coordinate();
        void FieldView();
};
#endif