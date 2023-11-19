set(CMAKE_CXX_STANDARD 17)
set(CMAKE_PREFIX_PATH ~bin/ncurses)
project(game)
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})
add_executable(game.out main.cpp
 EventManager/EventManager.cpp
 EventManager/Event/TeleportEvent.h
 EventManager/Event/TeleportEvent.cpp
 EventManager/Event/NoneEvent.cpp
 EventManager/Event/TrapEvent.cpp
 EventManager/Event/TreatEvent.cpp
    Field/Field.cpp
    Field/FieldCreator.cpp
    Field/FieldCreator.h
    Field/Square.cpp
        Characteristic/Armor.cpp
        Characteristic/Characteristic.cpp
        Characteristic/Money.cpp
        Characteristic/Count.cpp
        Characteristic/Health.cpp
        Characteristic/Power.cpp
        Characteristic/Score.cpp
            Move/Coordinate.cpp
            Move/Direction.cpp
            Move/MoveManager.cpp  
                Item/Item.cpp
                Item/Weapon.cpp
                    Player.cpp
                        Game/GameManager.cpp
                            Input/IInput.cpp
                            Input/ConsoleInput.cpp
                            Input/FileConfigReader.cpp
                            Input/IConfigReader.cpp
                            Input/InputHandler.cpp
                                Command/ExitCommand.cpp
                                Command/ICommand.cpp
                                Command/MoveCommand.cpp
                            )
target_link_libraries(game.out ${CURSES_LIBRARIES})
