#ifndef MENU_H
#define MENU_H
#include"object.h"
#include "constants.h"

class Menu{
 private:
 SDL_Renderer *renderer;
 SDL_Window *window;
 TTF_Font* font;


public:
Menu();
~Menu();
SDL_Color color;
Object hnen;
bool running;
SDL_Rect score_board;
string level1,level2,mode1,mode2;
string score,score0,score1,score2,score3;
int easy=0;

    
     void draw(Object o);
     void write(string text, int x, int y);
   
     void renderMenu();
      
     void inputmenu();
     void run();
};
 
#endif