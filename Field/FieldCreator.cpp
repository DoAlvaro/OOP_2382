#include "FieldCreator.h"
#include "../Move/Coordinate.h"
#include "../EventManager/Event/Event.h"
#include "../EventManager/Event/NoneEvent.h"
#include "../EventManager/Event/TrapEvent.h"
#include "../EventManager/Event/TreatEvent.h"
#include "../EventManager/Event/TeleportEvent.h"
FieldCreator::FieldCreator() = default;
Field FieldCreator::creat_field_for_level(int level){
    switch (level)
    {
    case 1:
        return creat_field_for_level_1();
        break;
    case 2:
        return creat_field_for_level_2();
        break;
    default:
        throw std::invalid_argument("Нет такого лвла");
    }
}
Field FieldCreator::creat_field_for_level_1(){
    int height = 10;
    int width = 10;
    Coordinate start = Coordinate(0,0);
    Coordinate end = Coordinate(height - 1, width - 1);
    Field new_field = Field(height,width,start,end);
    for (int i = 0; i < 10; i++){
        for (int j = i+2; j <10; j++){
            new_field.getSquare(j,i).setPassable(false);
             new_field.getSquare(i,j).setPassable(false);
        }
    }
    Event* tp = new TeleportEvent(Coordinate(3,3));
    Event* trap = new TrapEvent(10000);
    Event* treat = new TreatEvent(10000);
    std::swap(new_field.getSquare(0,1).event,tp);
    std::swap(new_field.getSquare(3,4).event,trap);
    std::swap(new_field.getSquare(7,8).event,treat);
    return new_field;
}
Field FieldCreator::creat_field_for_level_2(){
    int height = 10;
    int width = 10;
    Coordinate start = Coordinate(0,0);
    Coordinate end = Coordinate(height - 1, width - 1);
    Field new_field = Field(height,width,start,end);
    Event* trap = new TrapEvent(10000);
    Event* treat = new TreatEvent(10000);
    std::swap(new_field.getSquare(3,4).event,trap);
    std::swap(new_field.getSquare(7,8).event,treat);
    return new_field;
}