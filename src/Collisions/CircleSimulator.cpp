#include "CircleSimulator.h"
#include <cmath>
#include <algorithm>

CircleSimulator::CircleSimulator(float w, float h, unsigned int circleAmount)
{
    areaWidth = w;
    areaHeight = h;
}

void CircleSimulator::addCircle(float x, float y, float r)
{
    Circle c(x,y,r);
    vecCircles.push_back(c);
}

void CircleSimulator::update(float dt)
{

}

void CircleSimulator::detectCollision(Circle &c1, Circle &c2)
{
    if(c1.doesCircleOverlap(c2))
    {

        vecCollidingCircles.push_back({&c1,&c2});
        float fDistance = sqrtf(powf(c1.posX-c2.posX,2.f)+powf(c1.posY-c2.posY,2.f));
        float fOverlap = 0.5f * (fDistance - c1.getRadius() - c2.getRadius());

        c1.posX -= fOverlap * (c1.posX-c2.posX)/fDistance;
        c1.posY -= fOverlap * (c1.posY-c2.posY)/fDistance;

        c2.posX +=  fOverlap * (c1.posX-c2.posX)/fDistance;
        c2.posY +=  fOverlap * (c1.posY-c2.posY)/fDistance;

    }
}

void CircleSimulator::handleCollision(std::pair<Circle*, Circle*> &c)
{

auto *c1 = c.first;
auto *c2 = c.second;
float fDistance = sqrtf(powf(c1->posX-c2->posX,2.f)+powf(c1->posY-c2->posY,2.f));
float nx = (c2->posX - c1->posX)/fDistance;
float ny = (c2->posY - c1->posY)/fDistance;

float tx = -ny;
float ty = nx;

float dpTan1 = c1->velX * tx + c1->velY * ty;
float dpTan2 = c2->velX * tx + c2->velY * ty;

float dpNorm1 = c1->velX * nx + c1->velY * ny;
float dpNorm2 = c2->velX * nx + c2->velY * ny;

float m1 = (dpNorm1 * (c1->getMass() - c2->getMass()) + 2.0f * c2->getMass() * dpNorm2) / (c1->getMass() + c2-> getMass());
float m2 = (dpNorm2 * (c2->getMass() - c1->getMass())+ 2.0f * c1->getMass() * dpNorm1) / (c1->getMass() + c2->getMass());

c1->velX = tx*dpTan1 + nx * m1;
c1->velY = ty*dpTan1 + ny * m1;
c2->velX = tx*dpTan2 + nx * m2;
c2->velY = ty*dpTan2 + ny * m2;


vecCollidingCircles.erase(std::remove(vecCollidingCircles.begin(), vecCollidingCircles.end(), c), vecCollidingCircles.end());


}

void CircleSimulator::moveCircle(Circle &c, float dt)
{

            c.accX = -c.velX*0.8f;
            c.accY = -c.velY*0.8f;
            c.velX += c.accX * dt;
            c.velY += c.accY * dt;
            c.posX += c.velX * dt;
            c.posY += c.velY * dt;

            if(c.posX<0.f) c.posX+=areaWidth;
            if(c.posX>=areaWidth) c.posX-=areaWidth;
            if(c.posY<0.f) c.posY+=areaHeight;
            if(c.posY>=areaHeight) c.posY-=areaHeight;

            if(c.velX*c.velX + c.velY*c.velY<=0.01f)
            {
                c.velX = 0.f;
                c.velY = 0.f;
            }
}

float CircleSimulator::getAreaHeight()
{
    return areaHeight;
}

float CircleSimulator::getAreaWidth()
{
    return areaWidth;
}
