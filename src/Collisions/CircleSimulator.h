#pragma once

#include "Circle.h"
#include <vector>
#include <utility>

class CircleSimulator
{

public:
    CircleSimulator(float w, float h, unsigned int circleAmount=10);

    void addCircle(float x, float y, float r);
    void update(float dt);
    std::vector<Circle> vecCircles;
    std::vector<std::pair<Circle*, Circle*>> vecCollidingCircles;

    void detectCollision(Circle &c1, Circle &c2);
    void handleCollision(std::pair<Circle*, Circle*> &c);
    void moveCircle(Circle &c, float dt);

    float getAreaWidth();
    float getAreaHeight();

private:
    float areaWidth;
    float areaHeight;
};