#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "customrectitem.h"
#include "rect.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , scene(new QGraphicsScene)
{
    ui->setupUi(this);
    view = new QGraphicsView(scene,this);
    ui->verticalLayout->addWidget(view);
    SquaredRect* squaredRect = new SquaredRect(0, 0, 200, 50);
    RoundedRect* roundedRect = new RoundedRect(250, 0, 150, 100, 25);

    scene->addItem(new CustomRectItem(squaredRect));
    scene->addItem(new CustomRectItem(roundedRect));
}

MainWindow::~MainWindow()
{
    delete ui;
}
