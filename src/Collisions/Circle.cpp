#include "Circle.h"
#include <cmath>

unsigned int Circle::instances = 0;

Circle::Circle()
{
    posX = 0.f;
    posY = 0.f;

    velX = 0.f;
    velY = 0.f;

    accX = 0.f;
    accY = 0.f;

    radius = 50.f;

    mass = radius * 10.f;

    id = instances++;

}

Circle::Circle(float posX, float posY, float radius)
{
    this->posX = posX;
    this->posY = posY;

    velX = 0.f;
    velY = 0.f;

    accX = 0.f;
    accY = 0.f;

    this->radius = radius;

    this->mass = radius*10.f;

    id = instances++;
}

void Circle::setRadius(float r)
{
    //no negative radius
    r = fabs(r);
    radius = r;
    mass = r*10.f;
}

float Circle::getRadius()
{
    return radius;
}

float Circle::getMass()
{
    return mass;
}

unsigned int Circle::getId()
{
    return id;
}
bool Circle::isPointInCircle(float x, float y)
{
    float distanceSquared = fabs((posX - x)*(posX - x) + (posY - y)*(posY-y));
    float radiusSquared = radius*radius;

    return distanceSquared<=radiusSquared;
}

bool Circle::doesCircleOverlap(const Circle& c)
{

    float distanceSquared = fabs((posX - c.posX)*(posX-c.posX) + (posY - c.posY)*(posY-c.posY));
    float sumSquared = (radius + c.radius)*(radius+c.radius);

    return distanceSquared<=sumSquared;
}