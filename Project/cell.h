#ifndef CELL_H
#define CELL_H

#include <QColor>
#include <QGraphicsItem>

class Cell : public QObject, public QGraphicsItem
{

    Q_OBJECT

public:
    Cell(QColor color, int x, int y, bool alive, bool next_alive);  //Constructor

    int get_x() {return x_;}  //Returns x coordinate
    int get_y() {return y_;}  //Returns y coordinate
    bool get_alive() {return alive_;}  //Returns alive
    void setAlive(bool a);
    void setColor(QColor c);

    //Need these functions
    QRectF boundingRect() const override;
    QPainterPath shape() const override;

    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

    void paint(QPainter* painter, const QStyleOptionGraphicsItem* item, QWidget* widget) override; //Changes color of the cell

    static int get_size() {return size_;} //Returns the width of the cell

signals:
//    void RightClick(Cell* c);
    void LeftClick(Cell* c);

protected:



private:
  int x_; //X coordinate
  int y_; //Y coordinate

  QColor color_; //Color of cell

  static const int size_ = 20; //Width of cell

  bool alive_; //Dead or alive

  bool next_alive_;
};

#endif
