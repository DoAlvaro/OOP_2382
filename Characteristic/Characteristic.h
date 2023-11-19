#ifndef Characteristic_h
#define Characteristic_h
class Characteristic
{
    protected:
        int value;
        int max_value;
        int min_value;
    public:
        Characteristic(int min_value,int max_value,int value);
        void setValue(int val);
        int getValue();
        int check(int value);
};
#endif
