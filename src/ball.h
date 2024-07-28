#ifndef BALL_H
#define BALL_H

#include "SDL.h"

class Ball {
public:
    Ball(const char* textureSheet, SDL_Renderer* ren, int x, int y);
    ~Ball();

    void update();
    void render();

private:
    int xpos;
    int ypos;
    int xvel;
    int yvel;

    SDL_Texture* ballTexture;
    SDL_Rect srcRect, destRect;
    SDL_Renderer* renderer;
};

#endif // BALL_H
