#ifndef GRID_H
#define GRID_H

#include "cell.h"

#include <vector>


class Grid
{
public:
    Grid();

private:
    vector<vector<Cell>> cell_grid; //Is a 2D vector that will contain all of the cells in the game
};

#endif // GRID_H
