#include "GameManager.h"
void GameManager::chooseLevel(int level){
    this->level = level;
}
bool GameManager::startLevel(){
    switch (level)
    {
    case 1:
        start_level_1();
        break;
    case 2:
        start_level_2();
        break;
    default:
        return false;
    }
    return true;
}
void GameManager::start_level_1(){
    Player player;
    Field field = FieldCreator().create_field_for_level(1);
    MoveManager playerContol(player,field);
    controller(playerContol);

}

void GameManager::start_level_2(){
    Player player;
    Field field = FieldCreator().create_field_for_level(2);
    MoveManager playerContol(player,field);
    controller(playerContol);
    
}
void GameManager::startGame(){
    std::cout << "Вы начали игру!";
    std::cout << "Введите уровень с которого хотите начать игру!";
    std::string level;
    while (true){
        
        std::cin >> level;
        try{
            chooseLevel(std::stoi(level));
        }
        catch(std::invalid_argument){
            chooseLevel(0);
        }
        if (!startLevel()){
            std::cout << "Вы ввели некорректный уровень! Попробуйте заново!";
        }
    }
}
bool GameManager::isLose(MoveManager& playerControl){
    return playerControl.getPlayer().health().isDead();
}
bool GameManager::isWin(MoveManager& playerControl){
    return playerControl.coordinate() == playerControl.getField().getEnd();
}
void GameManager::endLevel(bool win){
    if (win){
        std::cout << "Поздравляю, Вы прошли уровень!" << '\n';
    }
    else{
        std::cout << "Поздравляю, Вы мертвы! Теперь вы призрак!" << '\n';
    }
    char quit;
    std::cout << "Введите q, если хотите заверишть игру! Если введешь что-то другое игра начнется снова....Хахахаахаха\n";
    std::cin >> quit;
    if (quit == 'q'){
        exit(0);
    }
    std::cout << "Введите уровень с которого хотите начать игру!";
}
void GameManager::controller(MoveManager& playerControl){
    char dir;
    bool win;
    playerControl.FieldView();
    
    Input input;
    while (dir != 'q') {
        std::cin >> dir;
        switch (dir) {
            case 's':
                playerControl.move(Direction::up);
                playerControl.FieldView();
                break;
            case 'w':
                playerControl.move(Direction::down);
                
                playerControl.FieldView();
                break;
            case 'a':
                playerControl.move(Direction::left);
                playerControl.FieldView();
                break;
            case 'd':
                playerControl.move(Direction::right);
                playerControl.FieldView();
                break;
        }
        if (isLose(playerControl)){
            win = false;
            break;
        }
        if (isWin(playerControl)){
            win = true;
            break;
        }
    }
    
    endLevel(win);
}