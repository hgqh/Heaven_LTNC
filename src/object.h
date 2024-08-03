#ifndef OBJECT_H
#define OBJECT_H

#include "SDL.h"

class Ball {
public:
    Ball();
    ~Ball();

    void update();
    void render();

private:
    SDL_Rect ballRect;
    SDL_Texture* texture;
};

class Paddle {
public:
    Paddle();
    ~Paddle();

    void update();
    void render();

private:
    SDL_Rect paddleRect;
    SDL_Texture* texture;
};

class Object {
public:
    Object();
    ~Object();

    void update();
    void render();

private:
    SDL_Rect objectRect;
    SDL_Texture* texture;
};

#endif // OBJECT_H
