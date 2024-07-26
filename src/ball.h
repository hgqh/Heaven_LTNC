#ifndef BALL_H
#define BALL_H

#include "object.h"

class Ball : public Object {
public:
    int dx, dy;
    void move();
    void draw() override;
};

#endif // BALL_H
