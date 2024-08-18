#ifndef MENU_H
#define MENU_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include "object.h"
#include "constants.h"

class Menu {
private:
    SDL_Renderer *renderer;  // Renderer for drawing
    SDL_Window *window;      // Window for the game
    TTF_Font *font;          // Font for rendering text

    Mix_Music *gnhacnen;     // Background music
    Mix_Chunk *gHigh;        // Sound effect

    SDL_Rect score_board;    // Rect for score display

public:
    Menu();
    ~Menu();

    SDL_Color color;
    Object hnen;
    bool running;
    std::string level1, level2, mode1, mode2;
    std::string score, score0, score1, score2, score3;
    int easy = 0;

    void draw(Object o);                     
    void write(std::string text, int x, int y);  // Write text to screen
    void renderMenu();
    void inputmenu();
    void run();
};

#endif
