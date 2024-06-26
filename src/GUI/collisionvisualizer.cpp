#include "collisionvisualizer.h"
#include "qevent.h"
#include <QPainter>
#include <QDebug>
CollisionVisualizer::CollisionVisualizer(QWidget *parent)
    : QWidget(parent)
{
    color1 = Qt::white;
    cs = new CircleSimulator(800.f,800.f);
    cs->addCircle(100.f,100.f,50.f);
    cs->addCircle(50.f,300.f,50.f);
    cs->addCircle(200.f,100.f,50.f);

    update();
}

CollisionVisualizer::~CollisionVisualizer()
{
    delete cs;
}

void CollisionVisualizer::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, false);

    painter.setBrush(color1);
    painter.setPen(Qt::PenStyle::NoPen);
    painter.drawRect(100, 100,100,100);
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
    QString xstr = QString::number(x);
    QString ystr = QString::number(y);
    qDebug(xstr.toLatin1()+","+ystr.toLatin1());
    color1 = Qt::green;
    update();
}


void CollisionVisualizer::mouseReleaseEvent(QMouseEvent *event)
{

}
