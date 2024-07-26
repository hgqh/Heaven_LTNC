#include "object.h"
#include <iostream>

void Object::draw() {
    std::cout << "Drawing object at (" << x << ", " << y << ")" << std::endl;
}

void Paddle::moveUp() {
    y -= 1; // Giả định tốc độ di chuyển là 1 đơn vị
}

void Paddle::moveDown() {
    y += 1; // Giả định tốc độ di chuyển là 1 đơn vị
}

void Paddle::draw() {
    std::cout << "Drawing paddle at (" << x << ", " << y << ") with size (" << width << ", " << height << ")" << std::endl;
}

void Ball::move() {
    x += dx;
    y += dy;
}

void Ball::draw() {
    std::cout << "Drawing ball at (" << x << ", " << y << ")" << std::endl;
}
