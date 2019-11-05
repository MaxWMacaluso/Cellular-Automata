#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_SpeedSlider_sliderMoved(int position);

    void on_StepButton_clicked();

    void on_PlayButton_clicked();

    void on_PauseButton_clicked();

private:
    Ui::MainWindow *ui;
};


//namespace Ui
//{
//class PlotWindow;
//}

//class PlotWindow : public QMainWindow
//{
//    Q_OBJECT

//public:
//    explicit PlotWindow(QWidget *parent = 0);
//    ~PlotWindow();

//private slots:
//    // default signal -> default slot
//    void on_randomButton_clicked();

//    // default signal -> custom slot
//    // 1. implement SlotTest
//    // 2. connect to a signal
//    void SlotTest();

//    void AddPoint();

//    void PointClickedSlot(int x, int y);

//private:
//    Ui::PlotWindow *ui;

//    QGraphicsScene *scene;

//    static int random_clicks_;
//};


#endif // MAINWINDOW_H
