#include "collisiondetectionpage.h"
#include "ui_collisiondetectionpage.h"

CollisionDetectionPage::CollisionDetectionPage(QStackedWidget *pages, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CollisionDetectionPage)
{
    ui->setupUi(this);

    auto *toMenuButton = ui->toMenuButton;
    auto *startButton = ui->startButton;
    auto *stopButton = ui->stopButton;
    auto *idk = new QVBoxLayout(ui->customwidget);
    visualizer = new CollisionVisualizer();
    idk->addWidget(this->visualizer);

    connect(toMenuButton, &QPushButton::clicked, [this,pages]{

        pages->removeWidget(this);
        delete this;
        pages->setCurrentIndex(1);

    });

    connect(startButton, &QPushButton::clicked, [this]{
        this->visualizer->startSimulation();
    });

    connect(stopButton, &QPushButton::clicked, [this]{
        this->visualizer->stopSimulation();
    });
}

CollisionDetectionPage::~CollisionDetectionPage()
{
    delete ui;
}
