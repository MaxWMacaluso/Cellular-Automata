#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{

}

void MainWindow::on_SpeedSlider_sliderMoved(int position)
{

}

void MainWindow::on_StepButton_clicked()
{

}

void MainWindow::on_PlayButton_clicked()
{

}

void MainWindow::on_PauseButton_clicked()
{

}
