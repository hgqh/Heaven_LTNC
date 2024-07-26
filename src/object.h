#ifndef OBJECT_H
#define OBJECT_H

class Object {
public:
    int x, y;
    virtual void draw();
};

class Paddle : public Object {
public:
    int width, height;
    void moveUp();
    void moveDown();
    void draw() override;
};

class Ball : public Object {
public:
    int dx, dy;
    void move();
    void draw() override;
};

#endif // OBJECT_H
