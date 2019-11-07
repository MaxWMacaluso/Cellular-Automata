#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cell.h"

#include <iostream>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QDebug>

#include <stdlib.h>
#include <time.h>
#include <QTimer>


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::TakeTurn(){

    //Colors of cells
    QColor red(Qt::red); //Alive
    QColor white(Qt::white); //Dead
    turn_ ++;
    ui->TurnLabel->setText(QString("Turn: ")+QString::number(turn_));
    vector<vector<Cell *>> cg = g.getCellGrid();
    vector<vector<Cell *>> to_update = g.getCellGrid();
    int aliveNeighbors = 0;
    for(int i=0; i< 10; i++){
        for (int j =0;j<20;j++){
          Cell * tmp = cg[i][j] ;
          aliveNeighbors = g.checkAliveAround(tmp);

          if (tmp->get_alive() == true){
              if (aliveNeighbors < 2){
                //dead
                tmp->setAlive(false);
                tmp->setColor(white);
                to_update[i][j] = tmp;
                currentPopulation_--;
              }
              if (aliveNeighbors ==2 | aliveNeighbors == 3){
                  //stays alive
              }
              if (aliveNeighbors > 3 ){
                  //dies
                  tmp->setAlive(false);
                  tmp->setColor(white);
                  to_update[i][j] = tmp;
                  currentPopulation_--;
              }
          }
          else{
              if (aliveNeighbors == 3 ){
                  //becomes alive
                  tmp->setAlive(true);
                  tmp->setColor(red);
                  to_update[i][j] = tmp;
                  currentPopulation_++;
              }
          }
        }
    }

    g.setCellGrid(to_update);
    ui->PopLabel->setText(QString("Population: ")+QString::number(currentPopulation_)+QString(" (")+QString::number((currentPopulation_*100)/200)+QString("%)"));
    scene->update();
}
void MainWindow::onPushButtonClicked()
{

}

void MainWindow::onSpeedSliderSliderMoved(int position)
{
//        speed_ = 1-(position/100.0);
//        ui->SpeeLabel->setText(QString("Speed: ")+QString::number(speed_, 'f', 6));
//        qDebug() << speed_;
}

void MainWindow::onStepButtonClicked()
{
    qDebug() << "step pressed!";
    TakeTurn();
}

void MainWindow::onPlayButtonClicked()
{
    TakeTurn();
    timer_->start(speed_*1000);
}

void MainWindow::onPauseButtonClicked()
{
    timer_->stop();
}

void MainWindow::LeftClickSlot(Cell * c){
    //int count = 0;
    //g.checkAliveAround(c);
    qDebug() << "alive around" << g.checkAliveAround(c);
    //count++;
    //qDebug() << count;
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

    g = Grid(scene, view);

    //connect left click feature to all cells ???********NEEDS TO CHANGE to correct LC feature ************
    vector<vector<Cell*>>  tmp = g.getCellGrid();
    for(vector<Cell *> v : tmp){
        for (Cell * c : v){
            connect(c,&Cell::LeftClick,this,&MainWindow::LeftClickSlot);
        }
    }

    //Connecting the signals and the slots
    connect(ui->StepButton, &QAbstractButton::clicked, this, &MainWindow::onStepButtonClicked);
    connect(ui->PlayButton, &QAbstractButton::clicked, this, &MainWindow::onPlayButtonClicked);
    connect(ui->PauseButton, &QAbstractButton::clicked, this, &MainWindow::onPauseButtonClicked);


    ui->TurnLabel->setText(QString("Turn: 0"));
    currentPopulation_ = g.getPopulation();
    ui->PopLabel->setText(QString("Population: ")+QString::number(currentPopulation_)+QString(" (")+QString::number((currentPopulation_*100)/200)+QString("%)"));
    srand(time(0));
    speed_ = 1.0;
    timer_ = new QTimer;
    connect(timer_, SIGNAL(timeout()), this, SLOT(onPlayButtonClicked()));
    //Will update the baord
    scene->update();
}





