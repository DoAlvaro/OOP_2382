#include <iostream>
#include "Player.h"
#include "Field/Field.h"

int main()
{
    
    Player player;
    Field field = Field(6,6,Coordinate(0,0),Coordinate(5,5));
    MoveManager playerContol(player,field);
    Player player2;
    for (int i = 0; i < field.getHeight(); i++){
        for (int j = 0; j < field.getWidth(); j++){
            std::cout << field.getSquare(i,j).getCoordinate().getX() << field.getSquare(i,j).getCoordinate().getY() << " ";
        }
        std::cout << '\n';
    }
    player.health().setValue(400);
    std::cout << "Оружие: " << player.weapon().getName() << std::endl;
    std::cout << "Расходники: " << player.item().getName() << std::endl;
    std::cout << "Характеристики: " << std::endl;
    std::cout << "Здоровье: " << player.health().getValue() << std::endl;
    std::cout << "Сила: " << player.power().getValue() << std::endl;
    std::cout << "Броня: " << player.armor().getValue() << std::endl;
    std::cout << "Монеты: " << player.money().getValue() << std::endl;
    std::cout << "Очки: " << player.score().getValue() << std::endl;
    std::cout << "Координата: " << playerContol.coordinate().getX() << " " << playerContol.coordinate().getY() << std::endl;
    playerContol.move(Direction::up);
    std::cout << "Координата: " << playerContol.coordinate().getX() << " " << playerContol.coordinate().getY() << std::endl;
    std::cout << field.getSquare(1,1).getPassable() << "<- до\n";
    // field.getSquare(1,1).setPassable(false);
    field.getSquare(1,1) = Square(false);
    for (int i = 0; i < field.getHeight(); i++){
        for (int j = 0; j < field.getWidth(); j++){
            std::cout << field.getSquare(i,j).getCoordinate().getX() << field.getSquare(i,j).getCoordinate().getY() << " ";
        }
        std::cout << '\n';
    }
    std::cout << field.getSquare(1,1).getPassable() << "<- проходимость\n";
    Field new_field = Field(field);
    Field new_field1(std::move(field));
    new_field.getSquare(1,1) = Square(false); 
    
    std::cout << new_field.getSquare(1,1).getPassable();
    return 0;
}