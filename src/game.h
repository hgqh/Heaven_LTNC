#ifndef GAME_H
#define GAME_H

#include "SDL.h"
#include <iostream>
#include <string>

class Game {
public:
    Game();
    ~Game();

    void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
    void handleEvents();
    void update();
    void render();
    void clean();

    bool running() { return isRunning; }

private:
    bool isRunning;
    SDL_Window* window;
    SDL_Renderer* renderer;

    SDL_Texture* loadTexture(const char* filePath);
    void write(const std::string& text, int x, int y, int r, int g, int b, int size);

    SDL_Rect ball, l_paddle, r_paddle;
    int l_s, r_s;
    int vX, vY;
    int turn;

    void serve();
    void variable();
    void draw(SDL_Texture* texture, SDL_Rect src, SDL_Rect dest);
};

#endif
