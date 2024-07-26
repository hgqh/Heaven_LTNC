#include "game.h"
#include "menu.h"

int main() {
    Menu menu;
    menu.display();

    Game game;
    game.init();
    game.update();
    game.render();

    return 0;
}
