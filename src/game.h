#ifndef GAME_H
#define GAME_H

class Game {
public:
    Paddle player1, player2;
    Ball ball;
    void init();
    void update();
    void render();
};

#endif // GAME_H
