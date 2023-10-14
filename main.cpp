#include <iostream> // 1
#include "Player.h" // 1
#include "Field/Field.h"
#include "EventManager/Event/Event.h"
#include "EventManager/Event/NoneEvent.h"
#include "EventManager/Event/TrapEvent.h"
#include "EventManager/Event/TreatEvent.h"

int main()
{
    Player player;
    Field field = Field(6,6,Coordinate(0,0),Coordinate(5,5));
    // Field field2 = Field(8,8,Coordinate(0,0),Coordinate(5,5));
    // field = field2;
    std::cout<<"SOZDAL!";
    MoveManager playerContol(player,field);
    Player player2;
    player.health().setValue(400);
    field.getSquare(1,1).getCoordinate() = Coordinate(222,22);
    std::cout << "Оружие: " << player.weapon().getName() << std::endl;
    std::cout << "Расходники: " << player.item().getName() << std::endl;
    std::cout << "Характеристики: " << std::endl;
    std::cout << "Здоровье: " << player.health().getValue() << std::endl;
    std::cout << "Сила: " << player.power().getValue() << std::endl;
    std::cout << "Броня: " << player.armor().getValue() << std::endl;
    std::cout << "Монеты: " << player.money().getValue() << std::endl;
    std::cout << "Очки: " << player.score().getValue() << std::endl;
    std::cout << '\n';
    std::cout << "Координата: " << playerContol.coordinate().getX() << " " << playerContol.coordinate().getY() << std::endl;
    // std::cout << "hio";
    playerContol.move(Direction::up);
    std::cout << "Координата: " << playerContol.coordinate().getX() << " " << playerContol.coordinate().getY() << std::endl;
    std::cout << field.getSquare(1,1).getPassable() << "<- до\n";
    std::cout << "А вот и наше поле:\n";
    // field.getSquare(1,1).setPassable(false);
    for (int i = 0; i < field.getHeight(); i++){
        for (int j = 0; j < field.getWidth(); j++){
            std::cout << field.getSquare(i,j).getCoordinate().getX() << field.getSquare(i,j).getCoordinate().getY() << " ";
        }
        std::cout << '\n';
    }
    std::cout << field.getSquare(1,1).getPassable() << "<- проходимость\n";
    Field new_field = Field(field);
    Field new_field1(std::move(field));
    TrapEvent trap = TrapEvent(200);
    TreatEvent treat = TreatEvent(1000);
    std::cout << "Очки: " << player.score().getValue() << std::endl;
    std::cout << "Здоровье: " << player.health().getValue() << std::endl;
    trap.start(playerContol);
    std::cout << "Здоровье: " << player.health().getValue() << std::endl;
    treat.start(playerContol);
    std::cout << "Здоровье: " << player.health().getValue() << std::endl;
    return 0;
}