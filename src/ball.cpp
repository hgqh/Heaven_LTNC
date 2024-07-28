#include "ball.h"
#include "SDL_image.h"

Ball::Ball(const char* textureSheet, SDL_Renderer* ren, int x, int y)
    : xpos(x), ypos(y), xvel(5), yvel(5) {
    renderer = ren;
    ballTexture = IMG_LoadTexture(renderer, textureSheet);

    srcRect = {0, 0, 32, 32}; 
    destRect = {xpos, ypos, 32, 32};
}

Ball::~Ball() {
    SDL_DestroyTexture(ballTexture);
}

void Ball::update() {
    xpos += xvel;
    ypos += yvel;

    // Phản xạ khi chạm tường
    if (xpos <= 0 || xpos + destRect.w >= 800) { 
        xvel = -xvel;
    }
    if (ypos <= 0 || ypos + destRect.h >= 600) { 
        yvel = -yvel;
    }

    destRect.x = xpos;
    destRect.y = ypos;
}

void Ball::render() {
    SDL_RenderCopy(renderer, ballTexture, nullptr, &destRect);
}
