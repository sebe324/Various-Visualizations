#include "opticspage.h"
#include "ui_opticspage.h"

OpticsPage::OpticsPage(QStackedWidget *pages, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OpticsPage)
{
    ui->setupUi(this);
}

OpticsPage::~OpticsPage()
{
    delete ui;
}
