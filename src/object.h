#ifndef OBJECT_H
#define OBJECT_H

#include <SDL2/SDL.h>

class Object {
public:
    int x, y;
    SDL_Rect rect;
    virtual void draw(SDL_Renderer* renderer) = 0;
};

#endif // OBJECT_H
