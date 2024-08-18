#ifndef GAME_H
#define GAME_H

#include "object.h"
#include "menu.h"
#include "constants.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include <string>

class Game {
public:
    Game();
    ~Game();
    
    SDL_Color color;
    bool running;

    SDL_Rect l_paddle, r_paddle, ball, tuong, tuong1;
    SDL_Rect score_board;

    int frameCount, timerFPS, lastFrame, fps;
    Object bgr, bgrMenu, bgr2, wall, wall1, m_ball, m_ball2, play, over, win, play1, play2;
    double vX, vY;
    std::string score, level1, level2, score1, mode1, mode2, score2, score3;
    int lastTime = 0;
    int l_s, r_s; 
    bool turn;
    Mix_Music *gnhacnen = NULL;
    Mix_Chunk *gHigh = NULL;
    int easy, mode, start, restart, run;
    int count = 0, count1 = 0;

    // Game logic methods
    void variable(); 
    void serve(); 
    void update(); 
    void inputgame(); 
    void rungame(); 
    void runback(); 

   
    void draw(Object o); 
    void renderMenu(); 
    void inputMenu(); 
    void runMenu(); 
    void rendergame(); 
    void write(std::string text, int x, int y, int r, int g, int b, int size); // Display text

    void loadAssets();  
    void displayMenuOptions();  

private:
    SDL_Renderer *renderer;
    SDL_Window *window;
    TTF_Font* font;


    void handlePaddleCollision(); 
    void calculateBounce(const SDL_Rect& paddle);
    void handleBallPosition(); 
    void handleMouseClick(SDL_Event& e);
  
    void manageFrameRate();
};

#endif
