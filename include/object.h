#ifndef OBJECT_H
#define OBJECT_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

class Object {
private:
    SDL_Rect dest; // Destination rectangle
    SDL_Rect src;  // Source rectangle
    SDL_Texture* tex; // Texture for the object

public:
    SDL_Rect getDest() const { return dest; }
    SDL_Rect getSource() const { return src; }
    
    void setDest(int x, int y, int w, int h);
    void setSource(int x, int y, int w, int h);

    // Load an image and create a texture
    void setImage(const std::string& filename, SDL_Renderer* renderer);

    SDL_Texture* getTex() const { return tex; }
};

#endif // OBJECT_H
