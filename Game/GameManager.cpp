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
    notify(ViewEvent::ChooseLevel);
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
            notify(ViewEvent::InvalidLevel);
        }else{
            this->startLevel();
        }
    }
}
bool GameManager::getWin(){
    return this->win;
}
bool GameManager::isLose(MoveManager& playerControl){
    return playerControl.getPlayer().health().isDead();
}
bool GameManager::isWin(MoveManager& playerControl){
    return playerControl.coordinate() == playerControl.getField().getEnd();
}
void GameManager::endLevel(bool win){
    notify(ViewEvent::EndGame);
    std::string quit;
    std::cin >> quit;
    if (quit == "q"){
        exit(0);
    }
    notify(ViewEvent::ChooseLevel);
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
    notify(ViewEvent::InitGame);
    while (true) {
        dir = input._read();
        config.handleInput(dir, *this);
        notify(ViewEvent::InitGame);
        if (isLose(playerControl)){
            this->win = false;
            break;
        }
        if (isWin(playerControl)){
            this->win = true;
            break;
        }
    }
    
    endLevel(win);
}

void GameManager::addObserver(Observer* observer)
{
    this->observers.push_back(observer);
}

void GameManager::removeObserver(Observer* observer)
{
    this->observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
}

void GameManager::notify(ViewEvent view_event)
{
    for (Observer* observer : observers)
        observer->update(view_event);
}