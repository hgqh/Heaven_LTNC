#include "object.h"
#include "SDL_image.h"

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

Object::Object(const char* textureSheet, SDL_Renderer* ren, int x, int y) {
    renderer = ren;
    objTexture = IMG_LoadTexture(renderer, textureSheet);

    xpos = x;
    ypos = y;
}

Object::~Object() {
    SDL_DestroyTexture(objTexture);
}

void Object::update() {
    
}

void Object::render() {
    SDL_RenderCopy(renderer, objTexture, nullptr, &destRect);
}
