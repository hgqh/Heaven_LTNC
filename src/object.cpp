#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "object.h"

// Set the destination rectangle (position and size)
void Object::setDest(int x, int y, int w, int h) {
    dest.x = x;
    dest.y = y;
    dest.w = w;
    dest.h = h;
}

// Set the source rectangle (portion of the image to display)
void Object::setSource(int x, int y, int w, int h) {
    src.x = x;
    src.y = y;
    src.w = w;
    src.h = h;
}

// Load an image from a file and create a texture
void Object::setImage(const std::string& filename, SDL_Renderer* renderer) {
    SDL_Surface* surf = IMG_Load(filename.c_str()); // Load image into surface
    if (!surf) {
        std::cerr << "Failed to load image: " << IMG_GetError() << std::endl;
        return;
    }
    tex = SDL_CreateTextureFromSurface(renderer, surf); // Convert surface to texture
    SDL_FreeSurface(surf); // Free the surface after creating the texture
}
