#include "paddle.h"
#include "SDL_image.h"

Paddle::Paddle(const char* textureSheet, SDL_Renderer* ren, int x, int y)
    : xpos(x), ypos(y), yvel(0) {
    renderer = ren;
    paddleTexture = IMG_LoadTexture(renderer, textureSheet);

    srcRect = {0, 0, 32, 128}; // Giả sử kích thước ảnh là 32x128
    destRect = {xpos, ypos, 32, 128};
}

Paddle::~Paddle() {
    SDL_DestroyTexture(paddleTexture);
}

void Paddle::handleEvents() {
    const Uint8* keystate = SDL_GetKeyboardState(nullptr);
    if (keystate[SDL_SCANCODE_UP]) {
        yvel = -5;
    } else if (keystate[SDL_SCANCODE_DOWN]) {
        yvel = 5;
    } else {
        yvel = 0;
    }
}

void Paddle::update() {
    ypos += yvel;

    
    if (ypos < 0) {
        ypos = 0;
    }
    if (ypos + destRect.h > 600) { 
        ypos = 600 - destRect.h;
    }

    destRect.y = ypos;
}

void Paddle::render() {
    SDL_RenderCopy(renderer, paddleTexture, nullptr, &destRect);
}
