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
    void TakeTurn();

public slots:
    void LeftClickSlot(Cell * c);

//PRIVATE VARIABLE
private:
    Ui::MainWindow* ui;
    QGraphicsScene* scene;

    Grid g; //Makes an instance of the board with pointers scene and view
    int turn_;
    int currentPopulation_;
    QTimer *timer_;
    double speed_;

//SLOTS
private slots:
    void onPushButtonClicked();
    void onSpeedSliderSliderMoved(int position);
    void onStepButtonClicked();
    void onPlayButtonClicked();
    void onPauseButtonClicked();



};


#endif
