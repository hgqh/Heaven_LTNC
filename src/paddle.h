#ifndef PADDLE_H
#define PADDLE_H

#include "SDL.h"

class Paddle {
public:
    Paddle(const char* textureSheet, SDL_Renderer* ren, int x, int y);
    ~Paddle();

    void handleEvents();
    void update();
    void render();

private:
    int xpos;
    int ypos;
    int yvel;

    SDL_Texture* paddleTexture;
    SDL_Rect srcRect, destRect;
    SDL_Renderer* renderer;
};

#endif // PADDLE_H
