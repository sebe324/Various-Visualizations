#ifndef COLLISIONVISUALIZER_H
#define COLLISIONVISUALIZER_H

#include <QPainter>
#include <QWidget>
#include "../Collisions/CircleSimulator.h"

class CollisionVisualizer : public QWidget
{

Q_OBJECT


public:
    CollisionVisualizer(QWidget *parent = nullptr);
    ~CollisionVisualizer();

protected:
    void paintEvent(QPaintEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;
    void mousePressEvent (QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
private:
    QTimer *timer;
    QBrush color1;
    CircleSimulator *cs;
};

#endif // COLLISIONVISUALIZER_H
