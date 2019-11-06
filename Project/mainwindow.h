#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGraphicsScene>
#include <QMainWindow>
#include <cell.h>

namespace Ui
{
class MainWindow;
}

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
    //static int random_clicks_;
    //Cell table[10][20]; // board of cells
    int population_;

//SLOTS
private slots:
    void onPushButtonClicked();
    void onSpeedSliderSliderMoved(int position);
    void onStepButtonClicked();
    void onPlayButtonClicked();
    void onPauseButtonClicked();


};


#endif
