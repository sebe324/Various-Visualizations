#include "collisiondetectionpage.h"
#include "ui_collisiondetectionpage.h"

CollisionDetectionPage::CollisionDetectionPage(QStackedWidget *pages, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CollisionDetectionPage)
{
    ui->setupUi(this);

    auto *toMenuButton = ui->toMenuButton;
    auto *idk = new QVBoxLayout(ui->customwidget);
    visualizer = new CollisionVisualizer();
    idk->addWidget(this->visualizer);

    connect(toMenuButton, &QPushButton::clicked, [this,pages]{

        pages->removeWidget(this);
        delete this;
        pages->setCurrentIndex(1);

    });
}

CollisionDetectionPage::~CollisionDetectionPage()
{
    delete ui;
}
