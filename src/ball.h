#ifndef BALL_H
#define BALL_H

#include "SDL.h"

class Ball {
public:
    Ball(int x, int y, int w, int h, int vX, int vY);
    void update();
    void render(SDL_Renderer* renderer);

    SDL_Rect getRect() const;

private:
    SDL_Rect rect;
    int velocityX;
    int velocityY;
};

#endif
