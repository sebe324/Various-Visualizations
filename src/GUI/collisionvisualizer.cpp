#include "collisionvisualizer.h"
#include "qevent.h"
#include <QPainter>
#include <QDebug>
CollisionVisualizer::CollisionVisualizer(QWidget *parent)
: QWidget(parent)
{
    color1 = Qt::white;
    update();
}

CollisionVisualizer::~CollisionVisualizer()
{

}

void CollisionVisualizer::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, false);

    painter.setBrush(color1);
    painter.setPen(Qt::PenStyle::NoPen);
    painter.drawRect(100, 100,100,100);


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
