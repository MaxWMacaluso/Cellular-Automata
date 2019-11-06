#ifndef GRID_H
#define GRID_H

#include "cell.h"

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QDebug>
#include <vector>

using namespace std;


class Grid
{

public:
    //Constructor, on creation, will go through board and randomely create alive and dead cells
    Grid(QGraphicsScene* scene, QGraphicsView* view);

    //Defualt constructor
    Grid() {;}

private:
    vector<vector<Cell*>> cell_grid; //Is a 2D vector that will contain pointers of all the cells in the game
};

#endif // GRID_H
