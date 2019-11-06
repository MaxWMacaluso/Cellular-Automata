#include "cell.h"

#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iostream>
#include <QtWidgets>

//CONSTRUCTOR
Cell::Cell(QColor color, const int x, const int y,bool a, int w, int h)
{
  this->color_ = color; //Sets the color
  x_ = x* (721/20); //Sets the x coordinate
  y_ = y * (301/10); //Sets the y coordinate
  alive_ = a; //Initializes it to a
}

//Defines clickable area
QRectF Cell::boundingRect() const
{
    return QRectF(x_, y_, width_, width_);
}

//Shape of object
QPainterPath Cell::shape() const
{
    QPainterPath path;
    path.addRect(x_, y_, width_, width_);
    return path;
}


//CHANGE COLOR
//If alive... have a color
//If dead... have be white
void Cell::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    Q_UNUSED(widget);

    QBrush b = painter->brush();
    painter->setBrush(QBrush(color_));

    painter->drawRect(QRect(this->x_, this->y_, this->width_, this->width_));
    painter->setBrush(b);
}

void Cell::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->buttons() == Qt::RightButton){
        emit RightClick(this);
    }
    if(event->buttons() == Qt::LeftButton){
        emit LeftClick(this);
    }

}




////Makes it so the == operator will have the behavior that you expect when comparing Cells.
//bool operator==(const Cell &first, const Cell &other)
//{
//  return first.x_ == other.x_ && first.y_ == other.y_;
//}
