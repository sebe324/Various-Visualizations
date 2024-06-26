#include "collisionvisualizer.h"
#include "qevent.h"
#include <QPainter>
#include <QDebug>
#include <QTimer>
#include <QApplication>

CollisionVisualizer::CollisionVisualizer(QWidget *parent)
    : QWidget(parent)
{
    color1 = Qt::white;
    cs = new CircleSimulator(800.f,400.f);
    cs->addCircle(100.f,100.f,50.f);
    cs->addCircle(50.f,300.f,50.f);
    cs->addCircle(200.f,100.f,50.f);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &CollisionVisualizer::updateSimulation);
    selectedCircle = nullptr;
    update();
}

CollisionVisualizer::~CollisionVisualizer()
{
    delete cs;
}

void CollisionVisualizer::updateSimulation()
{
    float dt = 0.017f;
    float simt = dt/4.f;
    for(int i = 0; i < 4; i++)
    {

        for(auto &ball : cs->vecCircles)
        {
            for(auto &target : cs->vecCircles)
            {
                if(ball.getId() != target.getId())
                {
                    cs->detectCollision(ball,target);
                }

            }
        }

        for(int b = 0; b<cs->vecCircles.size(); b++)
        {
            cs->moveCircle(cs->vecCircles[b],simt);
        }

        for (auto &c : cs->vecCollidingCircles)
        {
            cs->handleCollision(c);
        }
    }

    update();
}

void CollisionVisualizer::startSimulation()
{
    timer->start(5);
}

void CollisionVisualizer::stopSimulation()
{
    timer->stop();
}
void CollisionVisualizer::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, false);

    painter.setBrush(color1);
    painter.setPen(Qt::PenStyle::NoPen);
    for(auto &c: cs->vecCircles)
    {
        QPointF center(c.posX,c.posY);
        painter.drawEllipse(center,c.getRadius(),c.getRadius());
    }


}

void CollisionVisualizer::resizeEvent(QResizeEvent *event)
{

}

void CollisionVisualizer::mousePressEvent ( QMouseEvent * event )
{
    QPointF pos = event->position();
    qreal x = pos.x();
    qreal y = pos.y();
    selectedCircle = nullptr;

    for(auto &c : cs->vecCircles)
    {
        if(c.isPointInCircle(x,y))
        {
            selectedCircle = &c;
            break;
        }
    }

    update();
}

void CollisionVisualizer::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::MouseButton::LeftButton)
    selectedCircle = nullptr;

    else if(event->button() == Qt::MouseButton::RightButton)
    {
    if(selectedCircle != nullptr)
    {
        QPointF pos = event->position();
        qreal x = pos.x();
        qreal y = pos.y();
        selectedCircle->velX = 5.0f * (selectedCircle->posX - x);
        selectedCircle->velY = 5.0f * (selectedCircle->posY - y);
    }
    }
}

void CollisionVisualizer::mouseMoveEvent(QMouseEvent *event)
{
    if(QApplication::mouseButtons() == Qt::MouseButton::LeftButton)
    {
    if(selectedCircle != nullptr){
        QPointF pos = event->position();
        qreal x = pos.x();
        qreal y = pos.y();
        selectedCircle->posX = x;
        selectedCircle->posY = y;
        update();
    }
    }
    else if(QApplication::mouseButtons()==Qt::MouseButton::RightButton)
    {

    }

}
