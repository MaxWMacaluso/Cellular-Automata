#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cell.h"

#include <iostream>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QDebug>

#include <stdlib.h>
#include <time.h>


MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::onPushButtonClicked()
{

}

void MainWindow::onSpeedSliderSliderMoved(int position)
{

}

void MainWindow::onStepButtonClicked()
{

}

void MainWindow::onPlayButtonClicked()
{

}

void MainWindow::onPauseButtonClicked()
{

}



MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    // we need to set up the ui before we draw on our scene
    ui->setupUi(this);

    //Scene is everything inside of the window
    scene = new QGraphicsScene;

    //view is the whole window
    QGraphicsView* view = ui->cellView;
    view->setScene(scene);
    view->setSceneRect(0, 0, view->frameSize().width() - 20, view->frameSize().height() - 20);


    //qDebug() << "Here's an example debugging statement";

//    //Makes an instance of the board with pointers scene and view
//    Grid g(scene, view);
      g = Grid(scene, view);

    //Connecting the signals and the slots
    connect(ui->StepButton, &QAbstractButton::clicked, this, &MainWindow::onStepButtonClicked);
    connect(ui->PlayButton, &QAbstractButton::clicked, this, &MainWindow::onPlayButtonClicked);
    connect(ui->PauseButton, &QAbstractButton::clicked, this, &MainWindow::onPauseButtonClicked);

    //Will update the baord
    scene->update();
}





