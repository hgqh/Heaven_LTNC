#include "game.h"

Game::Game() : isRunning(false), window(nullptr), renderer(nullptr) {}

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

        variable();
        serve();

        isRunning = true;
    } else {
        isRunning = false;
    }
}

void Game::variable() {
    l_s = r_s = 0;
    l_paddle.x = 32; l_paddle.h = 480 / 5;
    l_paddle.y = (480 / 2) - (l_paddle.h / 2);
    l_paddle.w = 12;
    r_paddle = l_paddle;
    r_paddle.x = 640 - r_paddle.w - 32;
    ball.w = ball.h = 16;
}

void Game::serve() {
    if (turn) {
        ball.x = l_paddle.x + (l_paddle.w * 4);
        vX = 4 / 2;
    } else {
        ball.x = r_paddle.x - (r_paddle.w * 4);
        vX = -4 / 2;
    }
    vY = 0;
    ball.y = 480 / 2 - 16 / 2;
    turn = !turn;
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
    }

    if (SDL_HasIntersection(&ball, &l_paddle)) {
        vX = -vX;
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
    
}

void Game::draw(SDL_Texture* texture, SDL_Rect src, SDL_Rect dest) {
    SDL_RenderCopy(renderer, texture, &src, &dest);
}
