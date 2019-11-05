#include "cell.h"

#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iostream>
#include <QtWidgets>

//CONSTRUCTOR
Cell::Cell(QColor color, const int x, const int y)
{
  this->color_ = color;
  x_ = x;
  y_ = y;
}

//NOT SURE
QRectF Cell::boundingRect() const
{
    return QRectF(x_, y_, width_, width_);
}

//SHAPE OF CELL
QPainterPath Cell::shape() const
{
    QPainterPath path;
    path.addEllipse(x_, y_, width_, width_);
    return path;
}


//CHANGE COLOR
void Cell::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    Q_UNUSED(widget);

    QBrush b = painter->brush();
    painter->setBrush(QBrush(color_.dark(option->state & QStyle::State_Sunken ? 120 : 100)));

    painter->drawEllipse(QRect(this->x_, this->y_, this->width_, this->width_));
    painter->setBrush(b);
}


void Cell::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
    // Day 2, Task 3
    qDebug() << x_;
    qDebug() << y_;
    qDebug() << "Cell clicked!";
    emit CellSelected(x_, y_);

    // Day 2, Task 4
    int red = rand() % 255;
    int green = rand() % 255;
    int blue = rand() % 255;
    QColor c(red, green, blue);
    color_ = c;

    // update this QGraphicsItem (force it to re-draw)
    update();
}

//CALCULATES DISTANCE BETWEEN THIS CELL AND ANOTHER CELL
//INPUT PARAMETER IS DISTANCE TO ANOTHER CELL
double Cell::Distance(const Cell &other) const
{
  double distance = (x_ - other.get_x()) * (x_ - other.get_x());
  distance += (y_ - other.y_) * (y_ - other.y_);
  return sqrt(distance);
}


//Makes it so the == operator will have the behavior that you expect when comparing Cells.
bool operator==(const Cell &first, const Cell &other)
{
  return first.x_ == other.x_ && first.y_ == other.y_;
}
