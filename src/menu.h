#ifndef MENU_H
#define MENU_H

#include "SDL.h"

class Menu {
public:
    Menu();
    ~Menu();

    void init(SDL_Renderer* renderer);
    void handleEvents();
    void render();
    void clean();

    bool isRunning() { return running; }

private:
    bool running;
    SDL_Renderer* renderer;
    SDL_Texture* backgroundTexture;
    SDL_Rect backgroundRect;

    SDL_Texture* loadTexture(const char* filePath);
    void draw(SDL_Texture* texture, SDL_Rect src, SDL_Rect dest);
};

#endif
