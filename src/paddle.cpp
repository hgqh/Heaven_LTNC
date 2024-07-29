#include "paddle.h"

Paddle::Paddle(int x, int y, int w, int h) {
    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;
    speed = 5;
}

void Paddle::handleEvents(const Uint8* keystates) {
    if (keystates[SDL_SCANCODE_W]) {
        rect.y -= speed;
    }
    if (keystates[SDL_SCANCODE_S]) {
        rect.y += speed;
    }
    if (keystates[SDL_SCANCODE_UP]) {
        rect.y -= speed;
    }
    if (keystates[SDL_SCANCODE_DOWN]) {
        rect.y += speed;
    }
}

void Paddle::update() {
    // Giới hạn paddle trong cửa sổ
    if (rect.y < 0) {
        rect.y = 0;
    }
    if (rect.y + rect.h > 480) {
        rect.y = 480 - rect.h;
    }
}

void Paddle::render(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &rect);
}

SDL_Rect Paddle::getRect() const {
    return rect;
}
