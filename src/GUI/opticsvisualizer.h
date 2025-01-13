#ifndef OPTICSVISUALIZER_H
#define OPTICSVISUALIZER_H

#include <QPainter>
#include <QWidget>
#include <QTimer>

class OpticsVisualizer : public QWidget
{
    Q_OBJECT

public:
    OpticsVisualizer(QWidget *parent = nullptr);
    ~OpticsVisualizer();

public slots:
    void updateSimulation();
protected:
    void paintEvent(QPaintEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
private:
    QTimer *timer;
    QBrush colorFocalPoint;
    QBrush colorLense;
    QBrush colorLine1;
    QBrush colorLine2;
    QBrush colorLine3;
    float pos=0.f;

};

#endif // OPTICSVISUALIZER_H
