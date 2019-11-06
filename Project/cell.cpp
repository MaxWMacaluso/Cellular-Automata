#include "cell.h"

#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iostream>
#include <QtWidgets>

//CONSTRUCTOR
Cell::Cell(QColor color, const int x, const int y, bool alive)
{
  this->color_ = color; //Sets the color

  x_ = x * (721 / 20); //Sets the x coordinate
  y_ = y * (301 / 10); //Sets the y coordinate

  alive_ = alive; //Initializes it to a

}

//Defines clickable area
QRectF Cell::boundingRect() const
{
    return QRectF(x_, y_, size_, size_);
}

//Shape of object
QPainterPath Cell::shape() const
{
    QPainterPath path;
    path.addRect(x_, y_, size_, size_);
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

    painter->drawRect(QRect(this->x_, this->y_, this->size_, this->size_));
    painter->setBrush(b);
}
