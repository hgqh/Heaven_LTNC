#include <iostream>
#include <sstream>
#include "menu.h"
#include "constants.h"

// Constructor initializes SDL components, audio, and font
Menu::Menu() {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) 
        std::cout << "Failed at SDL_Init()" << std::endl;
    if (SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, 0, &window, &renderer) < 0) 
        std::cout << "Failed at SDL_CreateWindowAndRenderer()" << std::endl;
 
    // Initialize audio
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
    gnhacnen = Mix_LoadMUS("assets/audio/nhacnen.mp3");
    gHigh = Mix_LoadWAV("assets/audio/low.wav");

    // Play background music
    if (Mix_PlayingMusic() == 0) {
        Mix_PlayMusic(gnhacnen, -1);
    } else {
        if (Mix_PausedMusic() == 1) 
            Mix_ResumeMusic();
        else 
            Mix_PauseMusic();
    }
  
    // Initialize font
    TTF_Init();
    font = TTF_OpenFont("assets/fonts/Cookiemonster-gv11.ttf", FONT_SIZE);
}

// Destructor releases resources
Menu::~Menu() {
    Mix_FreeChunk(gHigh);
    Mix_FreeMusic(gnhacnen);
    TTF_CloseFont(font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

// Render text to the screen
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

// Handle user input in the menu
void Menu::inputmenu() {
    SDL_Event e;
    const Uint8 *keystates = SDL_GetKeyboardState(NULL);
    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_MOUSEMOTION) {
            // Display mouse position in the window title
            int mouseX = e.motion.x;
            int mouseY = e.motion.y;
            std::stringstream ss;
            ss << "X: " << mouseX << " Y: " << mouseY;
            SDL_SetWindowTitle(window, ss.str().c_str());
        } else if (e.type == SDL_MOUSEBUTTONDOWN) {
            // Handle mouse button clicks
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
    if (keystates[SDL_SCANCODE_ESCAPE]) running = 0; // Handle escape key press
}

// Draw an object to the screen
void Menu::draw(Object o) {
    SDL_Rect dest = o.getDest();
    SDL_Rect src = o.getSource();
    SDL_RenderCopyEx(renderer, o.getTex(), &src, &dest, 0, NULL, SDL_FLIP_NONE);
}

// Render the menu screen
void Menu::renderMenu() {
    SDL_RenderClear(renderer);
    hnen.setDest(0, 0, 1000, 600);
    hnen.setSource(0, 0, 2000, 1200);
    hnen.setImage("assets/images/backgrounds/bgr.jpg", renderer);
    draw(hnen);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    
    write(level1, WIDTH/2-215, FONT_SIZE*6-100);
    write(level2, WIDTH/2-215, FONT_SIZE*6+100);
    write(score1, WIDTH/2-215, FONT_SIZE*6);
    write(score2, WIDTH/2, FONT_SIZE*6);
    write(score3, WIDTH/2+415, FONT_SIZE*6);

    SDL_RenderPresent(renderer);
}

// Run the menu loop
void Menu::run() {
    running = 1;
    while (running) {
        renderMenu();
        inputmenu();
        if (easy == 1) running = 0; // Exit if the game starts
    }
}
