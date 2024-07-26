#include "object.h"
#include <SDL2/SDL.h>

void Object::draw(SDL_Renderer* renderer) {
    SDL_RenderFillRect(renderer, &rect);
}
