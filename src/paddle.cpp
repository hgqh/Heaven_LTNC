#include "paddle.h"
#include <SDL2/SDL.h>

void Paddle::moveUp() {
    y -= 5; // Giả định tốc độ di chuyển là 5 đơn vị
    rect = { x, y, width, height };
}

void Paddle::moveDown() {
    y += 5; // Giả định tốc độ di chuyển là 5 đơn vị
    rect = { x, y, width, height };
}

void Paddle::draw(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Màu đỏ
    SDL_RenderFillRect(renderer, &rect);
}
