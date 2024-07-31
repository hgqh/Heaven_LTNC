#include "menu.h"
#include <iostream>

Menu::Menu() : running(false), renderer(nullptr), backgroundTexture(nullptr) {}

Menu::~Menu() {}

void Menu::init(SDL_Renderer* renderer) {
    this->renderer = renderer;
    backgroundTexture = loadTexture("media/menu_background.bmp");
    if (backgroundTexture == nullptr) {
        std::cout << "Failed to load background texture!" << std::endl;
    }
    backgroundRect = {0, 0, 640, 480};
    running = true;
}

SDL_Texture* Menu::loadTexture(const char* filePath) {
    SDL_Texture* texture = nullptr;
    SDL_Surface* tempSurface = SDL_LoadBMP(filePath);
    if (tempSurface == nullptr) {
        std::cout << "Unable to load image " << filePath << "! SDL Error: " << SDL_GetError() << std::endl;
    } else {
        texture = SDL_CreateTextureFromSurface(renderer, tempSurface);
        SDL_FreeSurface(tempSurface);
    }
    return texture;
}

void Menu::handleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            running = false;
        }
        if (event.type == SDL_MOUSEBUTTONDOWN) {
            int mouseX = event.motion.x;
            int mouseY = event.motion.y;
            if (event.button.button == SDL_BUTTON_LEFT && mouseX >= 100 && mouseX <= 200 && mouseY >= 100 && mouseY <= 200) {
                running = false;
            }
        }
    }
}

void Menu::render() {
    SDL_RenderClear(renderer);
    draw(backgroundTexture, backgroundRect, backgroundRect);
    SDL_RenderPresent(renderer);
}

void Menu::clean() {
    SDL_DestroyTexture(backgroundTexture);
    backgroundTexture = nullptr;
}

void Menu::draw(SDL_Texture* texture, SDL_Rect src, SDL_Rect dest) {
    SDL_RenderCopy(renderer, texture, &src, &dest);
}
