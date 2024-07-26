#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include "paddle.h"
#include "ball.h"

class Game {
public:
    SDL_Window* window;
    SDL_Renderer* renderer;
    Paddle player1, player2;
    Ball ball;
    bool isRunning;

    Game();
    ~Game();
    void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
    void handleEvents();
    void update();
    void render();
    void clean();
};

#endif // GAME_H
