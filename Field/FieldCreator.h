#ifndef FieldCreator_h
#define FieldCreator_h
#include "Field.h"
class FieldCreator{
    Field creat_field_for_level_1();
    Field creat_field_for_level_2();
    public:
        FieldCreator();
        Field creat_field_for_level(int level);
};
#endif