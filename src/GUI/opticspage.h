#ifndef OPTICSPAGE_H
#define OPTICSPAGE_H

#include <QWidget>
#include <QStackedWidget>
#include <QTimer>
#include "opticsvisualizer.h"
namespace Ui {
class OpticsPage;
}

class OpticsPage : public QWidget
{
    Q_OBJECT

public:
    explicit OpticsPage(QStackedWidget *pages, QWidget *parent = nullptr);
    ~OpticsPage();
protected:
    void keyPressEvent(QKeyEvent *event) override;
private:
    Ui::OpticsPage *ui;
    OpticsVisualizer *visualizer;
};

#endif // OPTICSPAGE_H
