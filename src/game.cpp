#include "game.h"

Game::Game() : isRunning(false), window(nullptr), renderer(nullptr), gnhacnen(nullptr), gHigh(nullptr) {}

Game::~Game() {}

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

        Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);

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
    SDL_Quit();
    std::cout << "Game cleaned!" << std::endl;
}

SDL_Texture* Game::loadTexture(const char* filePath) {
    SDL_Texture* texture = nullptr;
    SDL_Surface* tempSurface = IMG_Load(filePath);
    if (tempSurface == nullptr) {
        std::cout << "Unable to load image " << filePath << "! SDL_image Error: " << IMG_GetError() << std::endl;
    } else {
        texture = SDL_CreateTextureFromSurface(renderer, tempSurface);
        SDL_FreeSurface(tempSurface);
    }
    return texture;
}

void Game::write(const std::string& text, int x, int y, int r, int g, int b, int size) {
    // Placeholder function for writing text
}

void Game::draw(SDL_Texture* texture, SDL_Rect src, SDL_Rect dest) {
    SDL_RenderCopy(renderer, texture, &src, &dest);
}
