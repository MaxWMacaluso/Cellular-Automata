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


void MainWindow::TakeTurn()
{

    //Colors of cells
    QColor red(Qt::red); //Alive
    QColor white(Qt::white); //Dead

    turn_++; //Add one to the value of turn

    //Update label
    ui->TurnLabel->setText(QString("Turn: ") + QString::number(turn_));

    //Will be a 2D vector which will be the next turn
    vector<vector<Cell*>> to_update = g.getCellGrid();

    //Each cell's alive neighbors
    int aliveNeighbors = 0;

    //Rows...
    for (int i = 0; i < 10; i++)
    {
        //Columns...
        for (int j = 0; j < 20; j++)
        {
          //Cell is equal to the current cell we are on in cell grid
          Cell* tmp = to_update[i][j];
          aliveNeighbors = g.checkAliveAround(tmp);

          //If cell is alive...
          if (tmp->get_alive() == true)
          {
              //Kill it next turn
              if (aliveNeighbors < 2)
              {
                tmp->setNextAlive(false);
                tmp->setColor(white);
                to_update[i][j] = tmp;
                currentPopulation_--;
              }
              //Stays a live next turn
              if (aliveNeighbors ==2 || aliveNeighbors == 3)
              {
                continue;
              }
              //Kill it next turn
              if (aliveNeighbors > 3 )
              {
                  tmp->setNextAlive(false);
                  tmp->setColor(white);
                  to_update[i][j] = tmp;
                  currentPopulation_--;
              }
          }
          //If cell is dead...
          else
          {
              //Becomes alive
              if (aliveNeighbors == 3 )
              {
                  tmp->setNextAlive(true);
                  tmp->setColor(red);
                  to_update[i][j] = tmp;
                  currentPopulation_++;
              }
          }
        }
    }

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            bool set_cell_state = to_update[i][j]->get_alive_next();
            to_update[i][j]->setAlive(set_cell_state);
        }
    }

    g.setCellGrid(to_update);
    ui->PopLabel->setText(QString("Population: ") + QString::number(currentPopulation_) + QString(" (") + QString::number((currentPopulation_ * 100) / 200) + QString("%)"));

    //Call the updateGraph function
    UpdateGraph();

    scene_->update();
}

void MainWindow::UpdateGraph()
{

}

void MainWindow::onPushButtonClicked()
{

}

void MainWindow::onSpeedSliderSliderMoved(int position)
{
        qDebug() << "Slider Moved";
        speed_ = 1-(position / 100.0);
        ui->SpeeLabel->setText(QString("Speed: ") + QString::number(speed_, 'f', 6));
        qDebug() << speed_;
}

void MainWindow::onStepButtonClicked()
{
    qDebug() << "step pressed!";
    TakeTurn();
}

void MainWindow::onPlayButtonClicked()
{
    TakeTurn();
    timer_->start(speed_ * 1000);
}

void MainWindow::onPauseButtonClicked()
{
    timer_->stop();
}

void MainWindow::LeftClickSlot(Cell* click)
{
    //int count = 0;
    //g.checkAliveAround(c);
    qDebug() << "alive around" << g.checkAliveAround(click);
    //count++;
    //qDebug() << count;
}

void MainWindow::onResetButtonClicked()
{
    //First clear the board and stop the timer
    scene_->clear();
    timer_->stop();

    //Call the makeWindow function
    makeWindow();
}

void MainWindow::makeWindow()
{
    //Need to set up the ui before we draw on our scene
    ui->setupUi(this);

    //SCENE 1 (Cell grid)
    scene_ = new QGraphicsScene; //Scene is everything inside of the window
    QGraphicsView* view = ui->cellView; //view is the whole window
    view->setScene(scene_);
    view->setSceneRect(0, 0, view->frameSize().width() - 20, view->frameSize().height() - 20);

    //SCENE 2 (Bar graph)
//    scene2 = new QGraphicsScene;
//    view->setScene(scene2);
//    view->setSceneRect(0, 0, view->frameSize().width() - 20, view->frameSize().height() - 20);


    g = Grid(scene_, view);

    //connect left click feature to all cells ???********NEEDS TO CHANGE to correct LC feature ************
    vector<vector<Cell*>>  tmp = g.getCellGrid();
    for (vector<Cell*> v : tmp)
    {
        for (Cell* c : v)
        {
            connect(c, &Cell::LeftClick, this, &MainWindow::LeftClickSlot);
        }
    }

    //Connecting the signals and the slots
    connect(ui->StepButton, &QAbstractButton::clicked, this, &MainWindow::onStepButtonClicked);
    connect(ui->PlayButton, &QAbstractButton::clicked, this, &MainWindow::onPlayButtonClicked);
    connect(ui->PauseButton, &QAbstractButton::clicked, this, &MainWindow::onPauseButtonClicked);
    connect(ui->ResetButton, &QAbstractButton::clicked, this, &MainWindow::onResetButtonClicked);
    connect(ui->SpeedSlider, &QSlider::valueChanged, this, &MainWindow::onSpeedSliderSliderMoved);


    ui->TurnLabel->setText(QString("Turn: 0"));
    currentPopulation_ = g.getPopulation();
    ui->PopLabel->setText(QString("Population: ") + QString::number(currentPopulation_) + QString(" (") + QString::number((currentPopulation_*100)/200) + QString("%)"));

    srand(time(0));
    speed_ = 1.0;
    timer_ = new QTimer;

    connect(timer_, SIGNAL(timeout()), this, SLOT(onPlayButtonClicked()));

    //Will update the baord
    scene_->update();
}

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    makeWindow();
}
