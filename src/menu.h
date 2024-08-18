#ifndef MENU_H
#define MENU_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include "object.h"
#include "constants.h"

class Menu {
private:
    SDL_Renderer *renderer;  
    SDL_Window *window;      
    TTF_Font *font;          

    Mix_Music *gnhacnen;     
    Mix_Chunk *gHigh;        

    SDL_Rect score_board;    

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
    void write(std::string text, int x, int y);
    void renderMenu();
    void inputmenu();
    void run();
};

#endif
