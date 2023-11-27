#include "ConsoleView.h"

ConsoleView::ConsoleView(GameManager *game) : game(game), game_observer(new GameObserver(game, this))
{
}

ConsoleView::~ConsoleView()
{
    delete game_observer;
}

void ConsoleView::update()
{
    system("clear");
    viewPlayer();
    std::cout << std::string(30, '-') << '\n';
    viewField();
}

void ConsoleView::updateChooseLevel()
{
    std::cout << "Вы начали игру!\n";
    std::cout << "Введите уровень с которого хотите начать игру!";
}

void ConsoleView::updateInvalidLevel()
{
    std::cout << "Вы ввели некорректный уровень! Попробуйте заново!";
}


void ConsoleView::updateEndGame()
{
    update();
    if (game->getWin()){
        std::cout << "Поздравляю, Вы прошли уровень!" << '\n';
    }
    else{
        std::cout << "Поздравляю, Вы мертвы! Теперь вы призрак!" << '\n';
    }
    std::cout << "Введите q, если хотите заверишть игру! Если введешь что-то другое игра начнется снова....Хахахаахаха\n";
}

void ConsoleView::viewField() {
    int w = game->getPlayerManager().getField().getWidth();
    int h = game->getPlayerManager().getField().getHeight();
    int x_start = 0;
    int y_start = 0;
    int x_end = 0;
    int y_end = 0;
    if (w <= 10 && h <= 10) {
        x_start = 0;
        y_start = 0;
        x_end = w;
        y_end = h;
    } else {
        int x_center = game->getPlayerManager().coordinate().getX();
        int y_center = game->getPlayerManager().coordinate().getY();
        
        if (x_center < 3) { x_start = 0; x_end = 7; }
        else if (x_center >= w-3) { x_start = w-7; x_end = w; }
        else { x_start = x_center - 3; x_end = x_center + 4; }

        if (y_center < 3) { y_start = 0; y_end = 7; }
        else if (y_center >= h-3) { y_start = h-7; y_end = h; }
        else { y_start = y_center - 3; y_end = y_center + 4; }
    }
    int x = game->getPlayerManager().coordinate().getX();
    int y = game->getPlayerManager().coordinate().getY();
    for (int i = y_start; i < y_end; i++) {
        for (int j = x_start; j < x_end; j++) {
            if (game->getPlayerManager().getField().getSquare(j, i).getPassable()) {
                if (x == j && y == i){
                    if (game->getPlayerManager().getPlayer().health().isDead()){
                        std::cout << "(X-X)";
                    }
                    else{
                        std::cout << "(T-T)";
                    }
                }
                else{
                    if (game->getPlayerManager().getField().getStart().getX() == i && game->getPlayerManager().getField().getStart().getY() == j){
                        std::cout << "  S  ";
                    }
                    else{if (game->getPlayerManager().getField().getEnd().getX() == i && game->getPlayerManager().getField().getEnd().getY() == j){
                        std::cout << "  F  ";
                    }
                    else{if (typeid(*(game->getPlayerManager().getField().getSquare(j,i).getEvent())) == typeid(TeleportEvent)){
                        std::cout << "  T  ";
                    }
                    else{
                    std::cout << "  .  ";
                    }
                    }}
                }
            } else {
                std::cout << " [#] ";
            }
        }
        std::cout << "\n";
    }
}
void ConsoleView::viewPlayer()
{
        std::cout << "Оружие: " << game->getPlayerManager().getPlayer().weapon().getName() << std::endl;
        std::cout << "Расходники: " << game->getPlayerManager().getPlayer().item().getName() << std::endl;
        std::cout << "Характеристики: " << std::endl;
        std::cout << "Здоровье: " << game->getPlayerManager().getPlayer().health().getValue() << std::endl;
        std::cout << "Сила: " << game->getPlayerManager().getPlayer().power().getValue() << std::endl;
        std::cout << "Броня: " << game->getPlayerManager().getPlayer().armor().getValue() << std::endl;
        std::cout << "Монеты: " << game->getPlayerManager().getPlayer().money().getValue() << std::endl;
        std::cout << "Сделано ходов: " << game->getPlayerManager().getPlayer().score().getValue() << std::endl;
}