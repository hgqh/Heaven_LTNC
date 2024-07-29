#ifndef PADDLE_H
#define PADDLE_H

#include "SDL.h"

class Paddle {
public:
    Paddle(int x, int y, int w, int h);
    void handleEvents(const Uint8* keystates);
    void update();
    void render(SDL_Renderer* renderer);

    SDL_Rect getRect() const;

private:
    SDL_Rect rect;
    int speed;
};

#endif
