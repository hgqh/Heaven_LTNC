#include "game.h"
#include "SDL_image.h"  // Bao gồm thư viện SDL_image
#include "SDL_ttf.h"
#include <iostream>

Game::Game() : isRunning(false), window(nullptr), renderer(nullptr), gnhacnen(nullptr), gHigh(nullptr), font(nullptr) {}

Game::~Game() {
    Mix_FreeChunk(gHigh);
    gHigh = nullptr;
    Mix_FreeMusic(gnhacnen);
    gnhacnen = nullptr;
    Mix_Quit();
    TTF_CloseFont(font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();
    std::cout << "Game cleaned!" << std::endl;
}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {
    int flags = 0;
    if (fullscreen) {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        std::cout << "SDL Initialized!" << std::endl;

        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if (window) {
            std::cout << "Window created!" << std::endl;
        }

        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer) {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            std::cout << "Renderer created!" << std::endl;
        }

        // Khởi tạo SDL_image
        int imgFlags = IMG_INIT_PNG;
        if (!(IMG_Init(imgFlags) & imgFlags)) {
            std::cout << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << std::endl;
        }

        Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
        TTF_Init();

        font = TTF_OpenFont("media/Peepo.ttf", 24);
        if (font == nullptr) {
            std::cout << "Failed to load font! SDL_ttf Error: " << TTF_GetError() << std::endl;
        }

        loadMedia();

        variable();
        serve();

        isRunning = true;
    } else {
        isRunning = false;
    }
}

void Game::loadMedia() {
    loadSounds();
}

void Game::loadSounds() {
    gnhacnen = Mix_LoadMUS("media/nhacnen.mp3");
    gHigh = Mix_LoadWAV("media/low.wav");

    if (Mix_PlayingMusic() == 0) {
        Mix_PlayMusic(gnhacnen, -1);
    }
}

void Game::handleEvents() {
    SDL_Event event;
    if (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                isRunning = false;
                break;
            default:
                break;
        }
    }
}

void Game::update() {
    ball.x += vX;
    ball.y += vY;

    if (ball.y <= 0 || ball.y + ball.h >= 480) {
        vY = -vY;
    }

    if (ball.x <= 0) {
        r_s++;
        serve();
    }

    if (ball.x + ball.w >= 640) {
        l_s++;
        serve();
    }

    if (SDL_HasIntersection(&ball, &r_paddle)) {
        vX = -vX;
        Mix_PlayChannel(-1, gHigh, 0);
    }

    if (SDL_HasIntersection(&ball, &l_paddle)) {
        vX = -vX;
        Mix_PlayChannel(-1, gHigh, 0);
    }
}

void Game::render() {
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderFillRect(renderer, &ball);

    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_RenderFillRect(renderer, &l_paddle);
    SDL_RenderFillRect(renderer, &r_paddle);

    SDL_RenderPresent(renderer);
}

void Game::clean() {
    Mix_FreeChunk(gHigh);
    gHigh = nullptr;
    Mix_FreeMusic(gnhacnen);
    gnhacnen = nullptr;
    Mix_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    TTF_CloseFont(font);
    TTF_Quit();
    SDL_Quit();
    std::cout << "Game cleaned!" << std::endl;
}

SDL_Texture* Game::loadTexture(const char* filePath) {
    SDL_Texture* texture = nullptr;
    SDL_Surface* tempSurface = IMG_Load(filePath);  // Sử dụng hàm IMG_Load
    if (tempSurface == nullptr) {
        std::cout << "Unable to load image " << filePath << "! SDL_image Error: " << IMG_GetError() << std::endl;  // Sử dụng hàm IMG_GetError
    } else {
        texture = SDL_CreateTextureFromSurface(renderer, tempSurface);
        SDL_FreeSurface(tempSurface);
    }
    return texture;
}

void Game::write(const std::string& text, int x, int y, int r, int g, int b, int size) {
    SDL_Surface *surface;
    SDL_Texture *texture;
    TTF_Font *font = TTF_OpenFont("media/Peepo.ttf", size);
    if (font == nullptr) {
        std::cout << "Failed to load font! SDL_ttf Error: " << TTF_GetError() << std::endl;
        return;
    }
    const char* t = text.c_str();
    color.r = r;
    color.g = g;
    color.b = b;
    color.a = 255;
    surface = TTF_RenderText_Solid(font, t, color);
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    score_board.w = surface->w;
    score_board.h = surface->h;
    score_board.x = x;
    score_board.y = y;
    SDL_FreeSurface(surface);
    SDL_RenderCopy(renderer, texture, NULL, &score_board);
    SDL_DestroyTexture(texture);
    TTF_CloseFont(font);
}

void Game::draw(SDL_Texture* texture, SDL_Rect src, SDL_Rect dest) {
    SDL_RenderCopy(renderer, texture, &src, &dest);
}
