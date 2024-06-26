#pragma once

class Circle
{
    private:
    static unsigned int instances;
    unsigned int id;

    float radius;
    float mass;

    public:
    float posX;
    float posY;

    float velX;
    float velY;

    float accX;
    float accY;

    float simElapsedTime;

    Circle();
    Circle(float posX, float posY, float radius=50.f);

    void setRadius(float r);


    float getRadius();
    float getMass();
    unsigned int getId();

    bool isPointInCircle(float x, float y);
    bool doesCircleOverlap(const Circle& c);

};