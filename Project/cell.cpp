#include "cell.h"

#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iostream>
#include <QtWidgets>

//CONSTRUCTOR
Cell::Cell(QColor color, int x, int y, bool alive, bool next_alive)
{
  this->color_ = color; //Sets the color

  x_ = x * (721 / 20); //Sets the x coordinate
  y_ = y * (301 / 10); //Sets the y coordinate

  alive_ = alive; //Initializes it to a

  next_alive_ = next_alive;
}

//void Cell::setAlive(bool alive)
//{
//    alive_ = alive;

//}

//void Cell::setColor(QColor color)
//{
//    color_ = color;
//}

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
//If dead... be white
void Cell::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    Q_UNUSED(widget);

    QBrush b = painter->brush();

    //If alive set color to red
    if (this->alive_ == true)
    {
        painter->setBrush(QBrush(Qt::red));
    }
    //If dead set color to white
    else
    {
        painter->setBrush(QBrush(Qt::white));
    }
    painter->drawRect(QRect(this->x_, this->y_, this->size_, this->size_));
    painter->setBrush(b);
}

void Cell::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
    if (event->buttons() == Qt::LeftButton)
    {
        emit LeftClick(this);
    }
    if (event->buttons() == Qt::RightButton)
    {
        emit RightClick(this);
    }

}
