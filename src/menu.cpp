#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <climits>
#include <sstream> 

#include "menu.h"
#include "constants.h"

Menu::Menu() {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) 
        std::cout << "Failed at SDL_Init()" << std::endl;
    if (SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, 0, &window, &renderer) < 0) 
        std::cout << "Failed at SDL_CreateWindowAndRenderer()" << std::endl;
 
    Mix_Music *gnhacnen = NULL;
    Mix_Chunk *gHigh = NULL;
    
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
    gnhacnen = Mix_LoadMUS("assets/audio/nhacnen.mp3");
    gHigh = Mix_LoadWAV("assets/audio/low.wav");
    if (Mix_PlayingMusic() == 0) 
        Mix_PlayMusic(gnhacnen, -1);
    else {
        if (Mix_PausedMusic() == 1) 
            Mix_ResumeMusic();
        else 
            Mix_PauseMusic();
    }
  
    TTF_Init();
    font = TTF_OpenFont("assets/fonts/Cookiemonster-gv11.ttf", FONT_SIZE);
}

Menu::~Menu() {

}

void Menu::write(std::string text, int x, int y) {
    SDL_Surface *surface;
    SDL_Texture *texture;
    const char *t = text.c_str();
    surface = TTF_RenderText_Solid(font, t, color);
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    score_board.w = surface->w;
    score_board.h = surface->h;
    score_board.x = x - score_board.w;
    score_board.y = y - score_board.h;
    SDL_FreeSurface(surface);
    SDL_RenderCopy(renderer, texture, NULL, &score_board);
    SDL_DestroyTexture(texture);
}

void Menu::inputmenu() {
    SDL_Event e;
    const Uint8 *keystates = SDL_GetKeyboardState(NULL);
    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_MOUSEMOTION) {
            int mouseX = e.motion.x;
            int mouseY = e.motion.y;
            std::stringstream ss;
            ss << "X: " << mouseX << " Y: " << mouseY;
            SDL_SetWindowTitle(window, ss.str().c_str());
        } else if (e.type == SDL_MOUSEBUTTONDOWN) {
            int mouseX = e.motion.x;
            int mouseY = e.motion.y;
            if (e.button.button == SDL_BUTTON_LEFT && mouseX >= 80 && mouseX <= 270 && mouseY >= 270 && mouseY <= 330) {
                level1 = " EASY  ";
                level2 = " HARD  ";
                score1 = " ";
            }
            if (e.button.button == SDL_BUTTON_LEFT && mouseX >= 110 && mouseX <= 270 && mouseY >= 170 && mouseY <= 225) {
                easy = 1;
            }
            if (e.button.button == SDL_BUTTON_LEFT && mouseX >= 101 && mouseX <= 273 && mouseY >= 371 && mouseY <= 425) {
                easy = 2;
            }
        }
    }
    if (keystates[SDL_SCANCODE_ESCAPE]) running = 0;
}

void Menu::draw(Object o) {
    SDL_Rect dest = o.getDest();
    SDL_Rect src = o.getSource();
    SDL_RenderCopyEx(renderer, o.getTex(), &src, &dest, 0, NULL, SDL_FLIP_NONE);
}

void Menu::renderMenu() {
    std::string level1, level2, mode1, mode2;
    std::string score, score0, score1, score2, score3;
    
    level1 = " "; level2 = " "; mode1 = " "; mode2 = " ";
    score1 = "  LEVEL  ";
    score2 = "  MODE ";
    score3 = "  PLAY ";
    
    SDL_RenderClear(renderer);
    hnen.setDest(0, 0, 1000, 600);
    hnen.setSource(0, 0, 2000, 1200);
    hnen.setImage("assets/images/backgrounds/anhnen.jpg", renderer);
    draw(hnen);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    
    write(level1, WIDTH/2-215, FONT_SIZE*6-100);
    write(level2, WIDTH/2-215, FONT_SIZE*6+100);
    write(score1, WIDTH/2-215, FONT_SIZE*6);
    write(score2, WIDTH/2, FONT_SIZE*6);
    write(score3, WIDTH/2+415, FONT_SIZE*6);

    SDL_RenderPresent(renderer);
}

void Menu::run() {
    running = 1;
    while (running) {
        std::string level1, level2, mode1, mode2;
        std::string score, score0, score1, score2, score3;
        
        level1 = " "; level2 = " "; mode1 = " "; mode2 = " ";
        score1 = "  LEVEL  ";
        score2 = "  MODE ";
        score3 = "  PLAY ";
        
        SDL_RenderClear(renderer);
        hnen.setDest(0, 0, 1000, 600);
        hnen.setSource(0, 0, 2000, 1200);
        hnen.setImage("assets/images/backgrounds/anhnen.jpg", renderer);
        draw(hnen);

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        write(level1, WIDTH/2-215, FONT_SIZE*6-100);
        write(level2, WIDTH/2-215, FONT_SIZE*6+100);
        write(score1, WIDTH/2-215, FONT_SIZE*6);
        write(score2, WIDTH/2, FONT_SIZE*6);
        write(score3, WIDTH/2+415, FONT_SIZE*6);

        SDL_RenderPresent(renderer);

        SDL_Event e;
        const Uint8 *keystates = SDL_GetKeyboardState(NULL);
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_MOUSEMOTION) {
                int mouseX = e.motion.x;
                int mouseY = e.motion.y;
                std::stringstream ss;
                ss << "X: " << mouseX << " Y: " << mouseY;
                SDL_SetWindowTitle(window, ss.str().c_str());
            } else if (e.type == SDL_MOUSEBUTTONDOWN) {
                int mouseX = e.motion.x;
                int mouseY = e.motion.y;
                if (e.button.button == SDL_BUTTON_LEFT && mouseX >= 80 && mouseX <= 270 && mouseY >= 270 && mouseY <= 330) {
                    level1 = " EASY  ";
                    level2 = " HARD  ";
                    score1 = " ";
                }
                if (e.button.button == SDL_BUTTON_LEFT && mouseX >= 110 && mouseX <= 270 && mouseY >= 170 && mouseY <= 225) {
                    easy = 1;
                }
                if (e.button.button == SDL_BUTTON_LEFT && mouseX >= 101 && mouseX <= 273 && mouseY >= 371 && mouseY <= 425) {
                    easy = 2;
                }
            }
        }
        if (keystates[SDL_SCANCODE_ESCAPE]) running = 0;
        if (easy == 1) running = 0;
    }
}
