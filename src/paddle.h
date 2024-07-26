#ifndef PADDLE_H
#define PADDLE_H

#include "object.h"

class Paddle : public Object {
public:
    int width, height;
    void moveUp();
    void moveDown();
    void draw() override;
};

#endif // PADDLE_H
