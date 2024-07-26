#include "ball.h"
#include <SDL2/SDL.h>

void Ball::move() {
    x += dx;
    y += dy;
    rect = { x, y, 20, 20 }; // Kích thước của bóng
}

void Ball::draw(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255); // Màu xanh dương
    SDL_RenderFillRect(renderer, &rect);
}
