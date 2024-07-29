#ifndef GAME_H
#define GAME_H

#include "SDL.h"
#include "ball.h"
#include "paddle.h"

class Game {
public:
    Game();
    ~Game();

    void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
    void handleEvents();
    void update();
    void render();
    void clean();
    bool isRunning() { return running; }

private:
    bool running;
    SDL_Window* window;
    SDL_Renderer* renderer;

    Ball* ball;
    Paddle* playerPaddle;
    Paddle* aiPaddle;
};

#endif // GAME_H
