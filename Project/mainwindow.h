#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGraphicsScene>
#include <QMainWindow>

namespace Ui
{
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow();


//PRIVATE VARIABLE
private:
    Ui::MainWindow* ui;
    QGraphicsScene* scene;
    //static int random_clicks_;

//SLOTS
private slots:
    void onPushButtonClicked();
    void onSpeedSliderSliderMoved(int position);
    void onStepButtonClicked();
    void onPlayButtonClicked();
    void onPauseButtonClicked();


};


#endif
