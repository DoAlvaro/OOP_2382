#include "GameManager.h"
#include <set>
#include <iostream>
GameManager::GameManager(IConfigReader &configgReader, ConsoleInput inputReader)
    : playerControl{player,field}, configReader{configgReader}, input{inputReader},config{InputHandler(configgReader)}{
    }
void GameManager::chooseLevel(int level){
    this->level = level;
}
bool GameManager::generateLevel(){
    switch (this->level)
    {
    case 1:
        generate_level_1();
        break;
    case 2:
        generate_level_2();
        break;
    default:
        return false;
    }
    return true;
}

void GameManager::generate_level_1(){
    Player player1;
    Field field1 = FieldCreator().create_field_for_level(1);
    this->player = player1;
    this->field = field1;
    MoveManager playerControl1(player1,field1);
    this->playerControl = playerControl1;
}

void GameManager::generate_level_2(){
    Player player1;
    Field field1 = FieldCreator().create_field_for_level(2);
    this->player = player1;
    this->field = field1;
    MoveManager playerControl1(player1,field1);
    this->playerControl = playerControl1;
    
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
        if (!generateLevel()){
            std::cout << "Вы ввели некорректный уровень! Попробуйте заново!";
        }else{
            this->startLevel();
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
MoveManager& GameManager::getPlayerManager(){
    return this->playerControl;
};
void GameManager::startLevel(){
    char dir;
    bool win;
    if (config.getTable().size() == 0) {
        throw(std::invalid_argument("Команды в файле указаны некорректно"));
    }
    playerControl.FieldView();
    while (true) {
        dir = input._read();
        config.handleInput(dir, *this);
        playerControl.FieldView();
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