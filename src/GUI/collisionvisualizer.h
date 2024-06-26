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

public slots:
    void updateSimulation();
    void startSimulation();
    void stopSimulation();
protected:
    void paintEvent(QPaintEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;
    void mousePressEvent (QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
private:
    QTimer *timer;
    QBrush color1;
    CircleSimulator *cs;
    Circle *selectedCircle;
    int maxSteps = 15;
};

#endif // COLLISIONVISUALIZER_H
