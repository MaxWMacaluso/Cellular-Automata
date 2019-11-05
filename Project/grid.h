#ifndef GRID_H
#define GRID_H

#include "cell.h"

#include <vector>

using namespace std;


class Grid
{
public:
    //Constructor, on creation, will go through board and randomely create alive and dead cells
    Grid();

private:
    vector<vector<Cell>> cell_grid; //Is a 2D vector that will contain all of the cells in the game
};

#endif // GRID_H
