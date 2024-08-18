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
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include "game.h"
#include "constants.h"

Game::Game(){
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
        std::cout << "Failed at SDL_Init()" << std::endl;
    if(SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, 0, &window, &renderer) < 0)
        std::cout << "Failed at SDL_CreateWindowAndRenderer()" << std::endl;

    // Audio
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
    gnhacnen = Mix_LoadMUS("assets/audio/nhacnen.mp3");
    gHigh = Mix_LoadWAV("assets/audio/low.wav");
    
  
    if (Mix_PlayingMusic() == 0) 
        Mix_PlayMusic(gnhacnen, -1);
    else if (Mix_PausedMusic() == 1)
        Mix_ResumeMusic();
    else 
        Mix_PauseMusic();
    
    // Fonts
    TTF_Init();
    font = TTF_OpenFont("assets/fonts/Cookiemonster-gv11.ttf", FONT_SIZE);


    loadAssets();
}

Game::~Game(){
    Mix_FreeChunk(gHigh);
    gHigh = NULL;
    Mix_FreeMusic(gnhacnen);
    gnhacnen = NULL;
    Mix_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_CloseFont(font);
    SDL_Quit();
}

void Game::loadAssets() {
    bgrMenu.setDest(0, 0, 1000, 600);
    bgrMenu.setSource(0, 0, 2000, 1200);
    bgrMenu.setImage("assets/images/backgrounds/bgr.jpg", renderer);
    
    bgr.setDest(0, 0, 1000, 600);
    bgr.setSource(0, 0, 2000, 1200);
    bgr.setImage("assets/images/backgrounds/bgr1.jpg", renderer);
    
    bgr2.setDest(0, 0, 1000, 600);
    bgr2.setSource(0, 0, 2000, 1200);
    bgr2.setImage("assets/images/backgrounds/bgr2.jpg", renderer);

    wall.setDest(300, 400, 160, 110);
    wall.setSource(0, 0, 1000, 1200);
    wall.setImage("assets/images/sprites/tieuhanhtinh.png", renderer);

    wall1.setDest(550, 150, 150, 100);
    wall1.setSource(0, 0, 1000, 1200);
    wall1.setImage("assets/images/sprites/tieuhanhtinh2.png", renderer);

    play.setDest(700, 300, 220, 180);
    play.setSource(0, 0, 2000, 1200);
    play.setImage("assets/images/sprites/play.png", renderer);

    m_ball.setDest(390, 220, 23, 23);
    m_ball.setSource(0, 0, 1000, 1200);
    m_ball.setImage("assets/images/sprites/thienthach.png", renderer);

    m_ball2.setDest(390, 220, 23, 23);
    m_ball2.setSource(0, 0, 1000, 1200);
    m_ball2.setImage("assets/images/sprites/thienthach.png", renderer);

    over.setDest(0, 0, 1000, 600);
    over.setSource(0, 0, 1000, 1200);
    over.setImage("assets/images/ui/gameover.jpg", renderer);

    win.setDest(0, 0, 1000, 600);
    win.setSource(0, 0, 1000, 1200);
    win.setImage("assets/images/ui/youwin.jpg", renderer);

    play1.setDest(0, 0, 1000, 600);
    play1.setSource(0, 0, 1000, 1200);
    play1.setImage("assets/images/sprites/player1.jpg", renderer);

    play2.setDest(0, 0, 1000, 600);
    play2.setSource(0, 0, 1000, 1200);
    play2.setImage("assets/images/sprites/player2.jpg", renderer);

    level1 = " ";
    level2 = " ";
    mode1 = " ";
    mode2 = " ";
    score1 = "  LEVEL  ";
    score2 = "  MODE ";
    score3 = "  PLAY ";
}


void Game::variable(){
    l_s = r_s = 0;
    l_paddle.x = 32; 
    l_paddle.h = HEIGHT / 5;
    l_paddle.y = (HEIGHT / 2) - (l_paddle.h / 2);
    l_paddle.w = 12;

    r_paddle = l_paddle;
    r_paddle.x = WIDTH - r_paddle.w - 32;

    tuong.x = 328; tuong.y = 415;
    tuong.w = 95; tuong.h = 80;

    tuong1.x = 565; tuong1.y = 155;
    tuong1.w = 101; tuong1.h = 85;

    ball.w = ball.h = SIZE;
}

// Serve the ball
void Game::serve(){
    if (turn) {
        ball.x = l_paddle.x + (l_paddle.w * 4);
        vX = BALL_SPEED / 2;
    } else {
        ball.x = r_paddle.x - (r_paddle.w * 4);
        vX = -BALL_SPEED / 2; 
    }
    vY = 0;
    ball.y = HEIGHT / 2 - SIZE / 2;
    m_ball.setDest(ball.x - 8, ball.y - 4, 23, 23);
    m_ball2.setDest(ball.x - 8, ball.y - 4, 25, 25);
    turn = !turn;
}


void Game::renderMenu(){
    SDL_RenderClear(renderer);
    draw(bgrMenu);
    if ((count == 1 && count1 == 1) || (count == 1 && count1 == 2) || (count == 2 && count1 == 1) || (count == 2 && count1 == 2))
        draw(play);
    
    displayMenuOptions();

    if (count == 0 || count == 1 || count == 2 || count1 == 1 || count1 == 2){
        write(score1, WIDTH / 2 - 215, FONT_SIZE * 6, 0, 0, 0, FONT_SIZE);
        write(score2, WIDTH / 2 + 100, FONT_SIZE * 6, 0, 0, 0, FONT_SIZE);
        SDL_RenderPresent(renderer);
    }  
}


void Game::displayMenuOptions() {
    if (count == 0 || count1 == 0){
        write(level1, WIDTH / 2 - 215, FONT_SIZE * 6 - 100, 0, 0, 0, FONT_SIZE);
        write(level2, WIDTH / 2 - 215, FONT_SIZE * 6 + 100, 0, 0, 0, FONT_SIZE);
        write(mode1, WIDTH / 2 + 100, FONT_SIZE * 6 - 100, 0, 0, 0, FONT_SIZE);
        write(mode2, WIDTH / 2 + 100, FONT_SIZE * 6 + 100, 0, 0, 0, FONT_SIZE);
    }
    if (count == 1){
        write(level1, WIDTH / 2 - 215, FONT_SIZE * 6 - 100, 255, 0, 0, FONT_SIZE);
        write(level2, WIDTH / 2 - 215, FONT_SIZE * 6 + 100, 0, 0, 0, FONT_SIZE);
    }
    if (count == 2){
        write(level1, WIDTH / 2 - 215, FONT_SIZE * 6 - 100, 0, 0, 0, FONT_SIZE);
        write(level2, WIDTH / 2 - 215, FONT_SIZE * 6 + 100, 255, 0, 0, FONT_SIZE);
    }
    if (count1 == 1){
        write(mode1, WIDTH / 2 + 100, FONT_SIZE * 6 - 100, 255, 0, 0, FONT_SIZE);
        write(mode2, WIDTH / 2 + 100, FONT_SIZE * 6 + 100, 0, 0, 0, FONT_SIZE);
    }
    if (count1 == 2){
        write(mode1, WIDTH / 2 + 100, FONT_SIZE * 6 - 100, 0, 0, 0, FONT_SIZE);
        write(mode2, WIDTH / 2 + 100, FONT_SIZE * 6 + 100, 255, 0, 0, FONT_SIZE);
    }
}

void Game::inputMenu(){
    std::stringstream ss;
    ss << "HEAVEN PONG";
    SDL_SetWindowTitle(window, ss.str().c_str());
    
    SDL_Event e;
    const Uint8 *keystates = SDL_GetKeyboardState(NULL);
    
    while (SDL_PollEvent(&e)){
        if (e.type == SDL_QUIT) running = 0, run = 1;
        handleMouseClick(e);
        if (keystates[SDL_SCANCODE_ESCAPE]) running = 0, run = 1;
        if (start == 1) running = 0;
    }
}


void Game::handleMouseClick(SDL_Event& e) {
    if (e.type == SDL_MOUSEBUTTONDOWN){
        int mouseX = e.motion.x;
        int mouseY = e.motion.y;

        if (e.button.button == SDL_BUTTON_LEFT && mouseX >= 80 && mouseX <= 270 && mouseY >= 270 && mouseY <= 330){
            level1 = " EASY  ";
            level2 = " HARD  ";
            score1 = " ";
        }

        if (e.button.button == SDL_BUTTON_LEFT && mouseX >= 110 && mouseX <= 270 && mouseY >= 170 && mouseY <= 225){
            easy = 1;
            count = 1;
        }
        if (e.button.button == SDL_BUTTON_LEFT && mouseX >= 101 && mouseX <= 273 && mouseY >= 371 && mouseY <= 425){
            easy = 2;
            count = 2;
        }
        if (e.button.button == SDL_BUTTON_LEFT && mouseX >= 450 && mouseX <= 580 && mouseY >= 275 && mouseY <= 330){
            mode1 = " 1 PLAYER";
            mode2 = " 2 PLAYER";
            score2 = " ";
        }
        if (e.button.button == SDL_BUTTON_LEFT && mouseX >= 375 && mouseX <= 600 && mouseY >= 170 && mouseY <= 225){
            mode = 1, count1 = 1;
        }
        if (e.button.button == SDL_BUTTON_LEFT && mouseX >= 365 && mouseX <= 600 && mouseY >= 371 && mouseY <= 425){
            mode = 2, count1 = 2;
        }
        if (e.button.button == SDL_BUTTON_LEFT && mouseX >= 700 && mouseX <= 920 && mouseY >= 352 && mouseY <= 441){
            start = 1;
        }
    }
}


void Game::runMenu(){
    running = 1;
    while (running){
        inputMenu();
        renderMenu();
    }
}

// Update game state
void Game::update(){
    score = "   SCORE :    " + std::to_string(l_s) + "              " + std::to_string(r_s) + "        (/5)"; 

    handlePaddleCollision();
    handleBallPosition();

    ball.x += vX;
    ball.y += vY;

    m_ball.setDest(ball.x - 8, ball.y - 4, 23, 23);
    m_ball2.setDest(ball.x - 8, ball.y - 4, 23, 23);
}


void Game::handlePaddleCollision() {
    if (SDL_HasIntersection(&ball, &r_paddle)) {
        Mix_PlayChannel(-1, gHigh, 0);
        calculateBounce(r_paddle);
    }
    if (SDL_HasIntersection(&ball, &l_paddle)) {
        Mix_PlayChannel(-1, gHigh, 0);
        calculateBounce(l_paddle);
    }
}


void
 Game::calculateBounce(const SDL_Rect& paddle) {
    double kc = (paddle.y + (paddle.h / 2)) - (ball.y + (SIZE / 2));
    double norm = kc / (paddle.h / 2);
    double bounce = norm * (5 * PI / 12);

    vX = BALL_SPEED * (paddle.x == r_paddle.x ? -cos(bounce) : cos(bounce));
    vY = BALL_SPEED * -sin(bounce);
}

// Handle ball position and scoring
void Game::handleBallPosition() {
    if (easy == 2) {
        if (SDL_HasIntersection(&tuong, &ball) || SDL_HasIntersection(&tuong1, &ball)){
            Mix_PlayChannel(-1, gHigh, 0);
            calculateBounce(l_paddle);
        }
    }
    if ((easy == 1 && mode == 1) || (easy == 2 && mode == 1)){
        if (ball.y > r_paddle.y + r_paddle.h / 2) r_paddle.y += SPEED - 2;
        if (ball.y < r_paddle.y + r_paddle.h / 2) r_paddle.y -= SPEED - 2;
    }
    if (ball.y <= 0 || ball.y + SIZE >= HEIGHT) vY = -vY;
    if (ball.x <= 0) {
        r_s++;
        serve();
    }
    if (ball.x >= WIDTH - SIZE) {
        l_s++;
        serve();
    }
    if (l_paddle.y < 0) l_paddle.y = 0;
    if (l_paddle.y + l_paddle.h > HEIGHT) l_paddle.y = HEIGHT - l_paddle.h;
    if (r_paddle.y < 0) r_paddle.y = 0;
    if (r_paddle.y + r_paddle.h > HEIGHT) r_paddle.y = HEIGHT - r_paddle.h;
}


void Game::inputgame(){
    SDL_Event e;
    const Uint8 *keystates = SDL_GetKeyboardState(NULL);
    while (SDL_PollEvent(&e)){
        if (e.type == SDL_QUIT) running = 0;
    }
  
    if ((easy == 1 && mode == 1) || (easy == 2 && mode == 1)){
        if (keystates[SDL_SCANCODE_ESCAPE]) running = 0;
        if (keystates[SDL_SCANCODE_UP]) l_paddle.y -= SPEED + 5;
        if (keystates[SDL_SCANCODE_DOWN]) l_paddle.y += SPEED + 5;
    }
    if ((easy == 1 && mode == 2) || (easy == 2 && mode == 2)){
        if (keystates[SDL_SCANCODE_ESCAPE]) running = 0;
        if (keystates[SDL_SCANCODE_W]) l_paddle.y -= SPEED + 5;
        if (keystates[SDL_SCANCODE_S]) l_paddle.y += SPEED + 5;
        if (keystates[SDL_SCANCODE_UP]) r_paddle.y -= SPEED + 5;
        if (keystates[SDL_SCANCODE_DOWN]) r_paddle.y += SPEED + 5;
    }
}


void Game::draw(Object o){
    SDL_Rect dest = o.getDest();
    SDL_Rect src = o.getSource();
    SDL_RenderCopyEx(renderer, o.getTex(), &src, &dest, 0, NULL, SDL_FLIP_NONE);
}


void Game::write(std::string text, int x, int y, int r, int g, int b, int size){
    SDL_Surface *surface;
    SDL_Texture *texture;
    TTF_OpenFont("assets/fonts/Cookiemonster-gv11.ttf", size);
    const char *t = text.c_str();
    color.r = r;
    color.g = g;
    color.b = b;
    color.a = 255;
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


void Game::rendergame(){
    if ((easy == 1 && mode == 1) || (easy == 1 && mode == 2)){
        SDL_RenderClear(renderer);
        draw(bgr);
        manageFrameRate();
        write(score, WIDTH / 2 + FONT_SIZE * 3 + 210, FONT_SIZE * 2, 0, 0, 0, 27);
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderFillRect(renderer, &l_paddle);
        SDL_RenderFillRect(renderer, &r_paddle);
        draw(m_ball);
        SDL_RenderPresent(renderer);
        if (r_s == 5 || l_s == 5) running = 0;
    }
    if (easy == 2 && mode == 1 || easy == 2 && mode == 2){
        SDL_RenderClear(renderer);
        draw(bgr2);
        draw(wall);
        draw(wall1);
        manageFrameRate();
        SDL_SetRenderDrawColor(renderer, 255, 185, 0, 255);
        write(score, WIDTH / 2 + FONT_SIZE * 3 + 210, FONT_SIZE * 2, 255, 255, 255, 37);
        SDL_RenderFillRect(renderer, &l_paddle);
        SDL_RenderFillRect(renderer, &r_paddle);
        draw(m_ball2);
        SDL_RenderPresent(renderer);
        if (r_s == 5 || l_s == 5) running = 0;
    }
}


void Game::manageFrameRate() {
    frameCount++;
    timerFPS = SDL_GetTicks() - lastFrame;
    if (timerFPS < (1000 / 60)){
        SDL_Delay((1000 / 60) - timerFPS);
    }
}


void Game::rungame(){
    running = 1;
    while (running){
        lastFrame = SDL_GetTicks();
        if (lastFrame >= (lastTime + 1000)){
            lastTime = lastFrame;
            fps = frameCount;
            frameCount = 0;
        }
        update();
        inputgame();
        rendergame();
    }
}

// Run the end-game screen
void Game::runback() {
    bool run = true; 
    while (run) {
        running = true;

        if (r_s == 5 && mode == 1) {
            running = false;
            draw(over);
            SDL_RenderPresent(renderer);
        } else if (l_s == 5 && mode == 1) {
            running = false;
            draw(win);
            SDL_RenderPresent(renderer);
        } else if (l_s == 5 && mode == 2) {
            running = false;
            draw(play1);
            SDL_RenderPresent(renderer);
        } else if (r_s == 5 && mode == 2) {
            running = false;
            draw(play2);
            SDL_RenderPresent(renderer);
        } else if (running) {
            
            draw(over);
            SDL_RenderPresent(renderer);
        }


        SDL_Event e;
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_MOUSEBUTTONDOWN) {
                int mouseX = e.motion.x;
                int mouseY = e.motion.y;


                if (e.button.button == SDL_BUTTON_LEFT && mouseX >= 360 && mouseX <= 640 && mouseY >= 320 && mouseY <= 400) {
                    restart = 1;
                    run = false; 
                }
                
                
                if (e.button.button == SDL_BUTTON_LEFT && mouseX >= 360 && mouseX <= 643 && mouseY >= 440 && mouseY <= 535) {
                    restart = 0;
                    run = false; 
                }
            }
        }
    }
}



