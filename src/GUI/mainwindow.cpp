#include "mainwindow.h"
#include "./ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    auto *pages = ui->stackedWidget;
    pages->setCurrentIndex(0);
    auto *actionExit = ui->actionExit;
    auto *actionSettings = ui->actionSettings;
    auto *actionAboutProject = ui->actionAbout_this_project;
    auto *actionAboutQt = ui->actionAbout_Qt;

    auto *startButton = ui->startButton;
    auto *aboutButton = ui->aboutButton;
    auto *exitButton = ui->exitButton;
    connect(actionExit,&QAction::triggered,[this]{this->close();});
    connect(exitButton, &QPushButton::clicked, [this]{this->close();});
    connect(startButton,&QPushButton::clicked, [this,pages]{
        this->menu = new CategoryMenu(pages, this);
        pages->addWidget(this->menu);
        pages->setCurrentIndex(1);
    });

}


MainWindow::~MainWindow()
{
    delete ui;
}

