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
    Grid() {}

    //Alters the cell_grid 2D vector with the new values for the cells after applying the supplied algo
    void next_turn();

private:
    vector<vector<Cell*>> cell_grid; //Is a 2D vector that will contain pointers of all the cells in the game
    int total_population_; //Holds the total population of the board
};

#endif // GRID_H
