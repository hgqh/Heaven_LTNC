#ifndef MENU_H
#define MENU_H

#include "SDL.h"

class Menu {
public:
    Menu();
    ~Menu();

    void render(SDL_Renderer* renderer);

private:
    SDL_Texture* menuTexture;
};

#endif // MENU_H
