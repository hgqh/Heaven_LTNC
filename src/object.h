#ifndef OBJECT_H
#define OBJECT_H

#include "SDL.h"

class Object {
public:
    Object(const char* textureSheet, SDL_Renderer* ren, int x, int y);
    ~Object();

    void update();
    void render();

private:
    int xpos;
    int ypos;

    SDL_Texture* objTexture;
    SDL_Rect srcRect, destRect;
    SDL_Renderer* renderer;
};

#endif // OBJECT_H
