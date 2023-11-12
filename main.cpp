#include <iostream> // 1
// #include "Player.h" // 1
// #include "Field/Field.h"
// #include "EventManager/Event/Event.h"
// #include "EventManager/Event/NoneEvent.h"
// #include "EventManager/Event/TrapEvent.h"
// #include "EventManager/Event/TreatEvent.h"
// #include "EventManager/Event/TeleportEvent.h"
// #include "Field/FieldCreator.h"
#include "Game/GameManager.h"
int main()
{
    GameManager game;
    game.startGame();
    return 0;
}
// г) Создать класс создающий поле. Предусмотреть возможность создания 2 разных уровней. По желанию можно сделать случайную генерацию уровней. Должно гарантироваться, что игрок может дойти от входа до выхода.

// Примечания:
// События должны быть такими, чтобы был сценарий проигрыша игрока.
// В событиях и клетках не должно быть полей сообщающих информацию о типе события
// Player player;
    // Field field = Field(6,6,Coordinate(0,0),Coordinate(5,5));
    // Field field2 = Field(8,8,Coordinate(0,0),Coordinate(5,5));
    // Field field = FieldCreator().creat_field_for_level(1);
    // std::cout<<"SOZDAL!";
    // MoveManager playerContol(player,field);
    // Player player2;
    // player.health().setValue(400);
    // field.getSquare(1,1).getCoordinate() = Coordinate(222,22);
    // std::cout << "Оружие: " << player.weapon().getName() << std::endl;
    // std::cout << "Расходники: " << player.item().getName() << std::endl;
    // std::cout << "Характеристики: " << std::endl;
    // std::cout << "Здоровье: " << player.health().getValue() << std::endl;
    // std::cout << "Сила: " << player.power().getValue() << std::endl;
    // std::cout << "Броня: " << player.armor().getValue() << std::endl;
    // std::cout << "Монеты: " << player.money().getValue() << std::endl;
    // std::cout << "Очки: " << player.score().getValue() << std::endl;
    // std::cout << '\n';
    // std::cout << "Координата: " << playerContol.coordinate().getX() << " " << playerContol.coordinate().getY() << std::endl;
    // std::cout << "hio";
    // playerContol.move(Direction::up);
    // std::cout << "Координата: " << playerContol.coordinate().getX() << " " << playerContol.coordinate().getY() << std::endl;
    // std::cout << field.getSquare(1,1).getPassable() << "<- до\n";
    // std::cout << "А вот и наше поле:\n";
    // field.getSquare(1,1).setPassable(false);
    // playerContol.FieldView();
    // std::cout << field.getSquare(1,1).getPassable() << "<- проходимость\n";
    // Field new_field = Field(field);
    // Field new_field(std::move(field));
    
    // TrapEvent trap = TrapEvent(200);
    // TreatEvent treat = TreatEvent(1000);
    // TeleportEvent tp = TeleportEvent(Coordinate(2,2));
    // std::cout << "Очки: " << player.score().getValue() << std::endl;
    // std::cout << "Здоровье: " << player.health().getValue() << std::endl;
    // trap.start(playerContol);
    // std::cout << "Здоровье: " << player.health().getValue() << std::endl;
    // treat.start(playerContol);
    // std::cout << "Координата: " << playerContol.coordinate().getX() << " " << playerContol.coordinate().getY() << std::endl;
    // tp.start(playerContol);
    // std::cout << "Координата: " << playerContol.coordinate().getX() << " " << playerContol.coordinate().getY() << std::endl;
    // std::cout << "Здоровье: " << player.health().getValue() << std::endl;
    // char dir;
    // playerContol.FieldView();
    // while (dir != 'q') {
    //     std::cin >> dir;
    //     switch (dir) {
    //         case 's':
    //             playerContol.move(Direction::up);
    //             playerContol.FieldView();
    //             break;
    //         case 'w':
    //             playerContol.move(Direction::down);
                
    //             playerContol.FieldView();
    //             break;
    //         case 'a':
    //             playerContol.move(Direction::left);
    //             playerContol.FieldView();
    //             break;
    //         case 'd':
    //             playerContol.move(Direction::right);
    //             playerContol.FieldView();
    //             break;
    //     }
    // }