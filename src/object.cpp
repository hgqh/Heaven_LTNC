#include "object.h"
#include "SDL_image.h"

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
