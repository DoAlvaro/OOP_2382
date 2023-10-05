#include <iostream>
#include <memory>
class Characteristic
{
    protected:
        int value;
        int max_value;
        int min_value;
    public:
        Characteristic(int min_value,int max_value,int value){
            this->max_value = std::max(min_value,max_value);
            this->min_value = std::min(min_value,max_value);
            setValue(value);
        }
        void operator=(Characteristic other){
            std::cout << "Попытка присваивания характеристики прервана\n";
        }
        void setValue(int val){
            int status = check(val);
            switch(status){
                case 0:
                    this->value = val;
                    break;
                case -1:
                    this->value = this->min_value;
                    break;
                case 1:
                    this->value = this->max_value;
                    break;
            }
        }
        
        int getValue() const{
            return this->value;
        }

        int check(int value){
            if (this->min_value > value) return -1;
            if (this->max_value < value) return 1;
            return 0;
        }
        
};

class Health : public Characteristic
{
    public:
        Health(int min_value,int max_value,int value): Characteristic(min_value, max_value, value){
            isDead();
        }
        bool isDead(){
            if (this->value <= this->min_value){
                this->is_dead = true;
                std::cout << "Поздравляю, Вы мертвы!" << '\n';
            }
            return is_dead;
        }
    private:
        bool is_dead = false;
};

class Power: public Characteristic
{
    public:
        Power(int min_value,int max_value,int value): Characteristic(min_value, max_value, value){}
};

class Armor: public Characteristic
{
    public:
        Armor(int min_value,int max_value,int value): Characteristic(min_value, max_value, value){}
};

class Money: public Characteristic
{
    public:
        Money(int min_value,int max_value,int value): Characteristic(min_value, max_value, value){}
};

class Score: public Characteristic
{
    public:
        Score(int min_value,int max_value,int value): Characteristic(min_value, max_value, value){}
};

class Count: public Characteristic
{
    public:
        Count(int min_value,int max_value,int value): Characteristic(min_value, max_value, value){}
};

enum class Direction{right,up,left,down};
class Event;

class Cell{
    bool isAbility = false;
    Event* event;
    public:
        Cell(bool isAbility, Event* event){
            this->isAbility = isAbility;
            this->event = event;
        }
};

class MoveManager;
class Coordinate
{
    friend MoveManager;
    int x;
    int y;
    public:
        Coordinate(int x, int y){
            this->x = x;
            this->y = y;
        }
        int getX(){
            return this->x;
        }
        int getY(){
            return this->y;
        }
        std::pair<int,int> getPair(){
            std::pair pair = std::make_pair(this->x,this->y);
            return pair;
        }
};





class Weapon
{
    int damage;
    std::string name;
    public:
        Weapon(std::string name, int damage, Power& power){
            this->name = name;
            this->damage = damage;
            use(power);
        }
        int getDamage(){return this->damage;}
        void setDamage(int damage){this->damage = damage;}
        std::string getName(){return this->name;}
        void setName(std::string name){this->name = name;}
        void use(Power& power){
            power.setValue(this->damage);
        }
};

class Item
{
    std::string name;
    Health* health;
    Power* power;
    Armor* armor;
    Count* count;
    public:
        Item(std::string name,int health=0, int power=0, int armor=0, int count=0){
            this->name = name;
            this->health = new Health(0,250,health);
            this->power = new Power(0,50,power);
            this->armor = new Armor(0,50,armor);
            this->count = new Count(0,16,count);
        }
        std::string getName(){return this->name;}
        void setName(std::string name){this->name = name;}
        
};


class Player
{
    Health default_health = Health(0,1000,10);
    Health& health = this->default_health;
    Power default_power = Power(0,100,0);
    Armor default_armor = Armor(0,100,0);
    Money default_money = Money(0,10000,600);
    Score default_score = Score(0,1000,0);
    Weapon default_weapon = Weapon("Кулаки",2,default_power);
    Item default_item = Item("Фласка",100,0,0,1);
    Coordinate default_coordinate = Coordinate(0,0);
    public:
        Health& heallth(){
            return this->health;
        }
        Power& power = this->default_power;
        Armor& armor = this->default_armor;
        Money& money = this->default_money;
        Score& score = this->default_score;
        Weapon& weapon = this->default_weapon;
        Item& item = this->default_item;
        Coordinate& coordinate = this->default_coordinate;
};

class MoveManager{
    Player* player;
    public:
        MoveManager(Player* player){
            this->player = player;
        }
        void move(Direction direction){
            switch (direction){
                case Direction::right:
                    this->player->coordinate.x += 1;
                    break;
                case Direction::left:
                    this->player->coordinate.x -= 1;
                    break;
                case Direction::up:
                    this->player->coordinate.y += 1;
                    break;
                case Direction::down:
                    this->player->coordinate.y -= 1;
                    break;
            }
        }
};

int main()
{
    Player player;
    MoveManager playerContol(&player);
    player.heallth() = Health(3121,321312,32112);
    std::cout << "Оружие: " << player.weapon.getName() << std::endl;
    std::cout << "Расходники: " << player.item.getName() << std::endl;
    std::cout << "Характеристики: " << std::endl;
    std::cout << "Здоровье: " << player.heallth().getValue() << std::endl;
    std::cout << "Сила: " << player.power.getValue() << std::endl;
    std::cout << "Броня: " << player.armor.getValue() << std::endl;
    std::cout << "Монеты: " << player.money.getValue() << std::endl;
    std::cout << "Очки: " << player.score.getValue() << std::endl;
    std::cout << "Координата: " << player.coordinate.getX() << " " << player.coordinate.getY() << std::endl;
    playerContol.move(Direction::up);
    std::cout << "Координата: " << player.coordinate.getX() << " " << player.coordinate.getY() << std::endl;
    return 0;
}