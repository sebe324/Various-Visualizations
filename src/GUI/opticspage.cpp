#include "opticspage.h"
#include "ui_opticspage.h"
#include <QDebug>
OpticsPage::OpticsPage(QStackedWidget *pages, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OpticsPage)
{
    ui->setupUi(this);
    auto *idk = new QVBoxLayout(ui->customwidget);
    visualizer = new OpticsVisualizer();
    idk->addWidget(this->visualizer);
}
void OpticsPage::keyPressEvent(QKeyEvent *event){
    qDebug("test");
    visualizer->updateSimulation();
};
OpticsPage::~OpticsPage()
{
    delete ui;
}
