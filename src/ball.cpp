#include "ball.h"

Ball::Ball(int x, int y, int w, int h, int vX, int vY) {
    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;
    velocityX = vX;
    velocityY = vY;
}

void Ball::update() {
    rect.x += velocityX;
    rect.y += velocityY;

    if (rect.y <= 0 || rect.y + rect.h >= 480) {
        velocityY = -velocityY;
    }
}

void Ball::render(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderFillRect(renderer, &rect);
}

SDL_Rect Ball::getRect() const {
    return rect;
}
