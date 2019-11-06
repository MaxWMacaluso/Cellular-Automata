#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGraphicsScene>
#include <QMainWindow>
#include <cell.h>

#include "grid.h"

namespace Ui
{
class MainWindow;
}

//Subclass of QMainWindow
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow(); //Deconstructor

public:

//PRIVATE VARIABLE
private:
    Ui::MainWindow* ui;
    QGraphicsScene* scene;
    int population_;

    Grid g; //Makes an instance of the board with pointers scene and view

//SLOTS
private slots:
    void onPushButtonClicked();
    void onSpeedSliderSliderMoved(int position);
    void onStepButtonClicked();
    void onPlayButtonClicked();
    void onPauseButtonClicked();

};


#endif
