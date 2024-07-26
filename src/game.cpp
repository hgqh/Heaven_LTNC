#include "game.h"
#include "paddle.h"
#include "ball.h"
#include <iostream>

void Game::init() {
    // Khởi tạo vị trí cho paddles và ball
    player1.x = 0; player1.y = 10; player1.width = 1; player1.height = 4;
    player2.x = 39; player2.y = 10; player2.width = 1; player2.height = 4;
    ball.x = 20; ball.y = 10; ball.dx = 1; ball.dy = 1;
    std::cout << "Game initialized" << std::endl;
}

void Game::update() {
    // Cập nhật vị trí của các đối tượng
    player1.moveUp();
    player2.moveDown();
    ball.move();
    std::cout << "Game updated" << std::endl;
}

void Game::render() {
    // Vẽ các đối tượng
    player1.draw();
    player2.draw();
    ball.draw();
    std::cout << "Game rendered" << std::endl;
}
