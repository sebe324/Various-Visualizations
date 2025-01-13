#include "opticsvisualizer.h"

#include "../Utilities/utils.h"
#include <QPainter>
#include <QDebug>
#include <QEvent>
#include <QKeyEvent>

OpticsVisualizer::OpticsVisualizer(QWidget *parent)
    : QWidget(parent)
{
    timer = new QTimer(this);
    colorLine1 = Qt::white;
}

OpticsVisualizer::~OpticsVisualizer()
{

}

void OpticsVisualizer::updateSimulation()
{
    pos+=0.1f;
    update();
}

void OpticsVisualizer::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, false);

    painter.setBrush(colorLine1);
    painter.setPen(Qt::PenStyle::NoPen);
    painter.drawRect(pos,0,50,50);
    qDebug("draw");
}

void OpticsVisualizer::keyPressEvent(QKeyEvent *event)
{
    pos+=0.1f;
    qDebug("key pressed");
    update();
}

void OpticsVisualizer::resizeEvent(QResizeEvent *event)
{

}

void OpticsVisualizer::mousePressEvent(QMouseEvent *event)
{

}

void OpticsVisualizer::mouseReleaseEvent(QMouseEvent *event)
{

}

void OpticsVisualizer::mouseMoveEvent(QMouseEvent *event)
{

}


