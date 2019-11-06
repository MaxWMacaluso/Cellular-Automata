#ifndef CELL_H
#define CELL_H

#include <QColor>
#include <QGraphicsItem>

class Cell : public QObject, public QGraphicsItem
{

    Q_OBJECT

public:
    Cell(QColor color, const int x, const int y, bool a ,int w, int h);  //Constructor

    int get_x() const {return x_;}  //Returns x coordinate
    int get_y() const {return y_;}  //Returns y coordinate

    //double Distance(const Cell &other) const;  //Calculates distance between 2 cells

    QRectF boundingRect() const override; //NOT SURE
    QPainterPath shape() const override; //Determines shape of the shell

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget) override; //Changes color of the cell

    static int get_width() {return width_;} //Returns the width of the cell

signals:
    //void CellSelected(int x, int y); //For distance
    void RightClick(Cell * c);
    void LeftClick(Cell * c);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent* event) override;



private:
  int x_; //X coordinate
  int y_; //Y coordinate
  QColor color_; //Color of cell
  static const int width_ = 20; //Width of cell
  //int height_ = 10
  bool alive_; //Dead or alive
};

#endif
