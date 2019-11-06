#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cell.h"

#include <iostream>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QDebug>

#include <stdlib.h>
#include <time.h>
#include <grid.h>


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



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    // we need to set up the ui before we draw on our scene
    ui->setupUi(this);

    // scene is a pointer field of plot window
    scene = new QGraphicsScene;

    // QGraphicsView is a container for a QGraphicsScene
    QGraphicsView * view = ui->cellView;
    view->setScene(scene);
    view->setSceneRect(0,0,view->frameSize().width()-20,view->frameSize().height()-20);


    //srand(time(0));


    qDebug() << "Here's an example debugging statement";
     Grid g(scene,view);


//    // create board... with lines and such
//    int cellHeight = view->frameSize().height()-20;
//    qDebug()<<cellHeight;
//    int cellWidth = view->frameSize().width()-20;
//    qDebug()<< cellWidth;
//    for(int i = 0; i < view->frameSize().width(); i += (cellWidth/20)) {
//            scene->addLine(i, 0, i, cellHeight);
//    }
//    for(int i = 0; i < view->frameSize().height(); i += (cellHeight/10)) {
//            scene->addLine(0, i, cellWidth, i);
//    }




//    /* initialize random seed: */
//    srand (time(NULL));

//    /* generate secret number between 0 and 10: */

//    int aliveProb;
//    bool aliveBOOL;
//    QColor green(Qt::green);
//    QColor red(Qt::gray);
//    QColor insert;
//    for(int i =0;i<10;i++){
//        for (int j=0;j<20;j++){
//            aliveProb = rand() % 10;
//            //qDebug() << aliveProb;
//            if(aliveProb < 5){
//                insert = green;
//                aliveBOOL = true;
//                population_++;
//            }
//            else{
//                insert = red;
//                aliveBOOL = false;
//            }
//            Cell * newCell = new Cell(insert, j, i, aliveBOOL,cellWidth/20,cellHeight/10);
//            //table[i][j] = newCell;
//            scene->addItem(newCell);
//        }
//    }





    connect(ui->StepButton, &QAbstractButton::clicked, this, &MainWindow::onStepButtonClicked);

    // signals and slots in Qt are loosely coupled

    // Day 2, Task 2
    connect(ui->PlayButton, &QAbstractButton::clicked, this, &MainWindow::onPlayButtonClicked);

    connect(ui->PauseButton, &QAbstractButton::clicked, this, &MainWindow::onPauseButtonClicked);


}


// Day 2, Task 2
//void MainWindow::AddPoint()
//{
//    bool safe = false;
//    int x = ui->xCoord->text().toInt(&safe);
//    if (!safe) {
//        return;
//    }
//    // do the same thing for the y coordinate
//    int y = ui->yCoord->text().toInt(&safe);
//    if (!safe) {
//        return;
//    }
//    // then create your point and add it to the scene!
//    QColor c(0, 0, 155);
//    int x_adj = x + (ui->plotGraphicsView->frameSize().width() / 2);
//    // account for the width of the point
//    x_adj = x_adj - Point::get_width() / 2;
//    int y_adj = (-1 * y + (ui->plotGraphicsView->frameSize().height() / 2));
//    // account for the height of the point (which is the same as the width because it's a circle)
//    y_adj = y_adj - Point::get_width() / 2;
//    Point * p = new Point(c, x_adj, y_adj);
//    connect(p, &Point::PointSelected, this, &MainWindow::PointClickedSlot);
//    scene->addItem(p);


//}

// Day 2, Task 3
//void MainWindow::PointClickedSlot(int x, int y)
//{
//    qDebug() << x;
//    qDebug() << y;
//    qDebug() << "point clicked slot!";
//    qDebug() << "you want your slot in the object that reacts to the signal!";
//    // for example:
//    std::string p1 = "Point 1: (" + std::to_string(x) + ", " + std::to_string(y) + ")";
//    QString s(p1.c_str());
//    ui->point1Label->setText(s);
//}






