#ifndef OPTICSPAGE_H
#define OPTICSPAGE_H

#include <QWidget>
#include <QStackedWidget>
namespace Ui {
class OpticsPage;
}

class OpticsPage : public QWidget
{
    Q_OBJECT

public:
    explicit OpticsPage(QStackedWidget *pages, QWidget *parent = nullptr);
    ~OpticsPage();

private:
    Ui::OpticsPage *ui;
};

#endif // OPTICSPAGE_H
