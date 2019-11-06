#include "grid.h"

#include <stdlib.h>
#include <time.h>



//Constructor, randomely creates a grib of alive and dead cells
Grid::Grid(QGraphicsScene *scene, QGraphicsView *view)
{
    //Creates a grid
    int cellHeight = view->frameSize().height() - 20;
    int cellWidth = view->frameSize().width() - 20;
    for (int i = 0; i < view->frameSize().width(); i += (cellWidth / 20))
    {
            scene->addLine(i, 0, i, cellHeight);
    }

    for (int i = 0; i < view->frameSize().height(); i += (cellHeight / 10))
    {
            scene->addLine(0, i, cellWidth, i);
    }

    //Seeds it. Do once
    srand (time(NULL));

    int aliveProb = 0;

    total_population_ = 0;

    bool alive = false;
    bool next_alive = false;

    //Colors of cells
    QColor red(Qt::red); //Alive
    QColor white(Qt::white); //Dead

    //Will be the color of the cell I create
    QColor cell_color;

    vector<Cell*> temp_row;

    //Traverses row
    for (int i = 0; i < 10; i++)
    {
        //Height
        for (int j = 0; j < 20; j++)
        {
            aliveProb = rand() % 10; //Random number [0, 10]

            //Alive cell...
            if (aliveProb < 5)
            {
                cell_color = red;
                alive = true;
                total_population_++;
            }
            //Dead cell...
            else
            {
                cell_color = white;
                alive = false;
            }

            //Create a new cell
            Cell* newCell = new Cell(cell_color, j, i, alive, next_alive);

            //Add each new cell in row to remp_row
            temp_row.push_back(newCell);

            scene->addItem(newCell);
        }

        //Once its gone through the whole row, add to final cell_grid
        cell_grid.push_back(temp_row);
    }
}

void Grid::next_turn(Cell* current_cell)
{
    int neighbor = 0;

    //Traverses row
    for (int i = 0; i < 10; i++)
    {
        //Height
        for (int j = 0; j < 20; j++)
        {
            //Top row special case
            if (i == 0)
            {

            }

            //Bottom row special case
            else if (i == 9)
            {

            }

            //Left column special case
            else if (j == 0)
            {

            }

            //Right column special case
            else if (j == 19)
            {

            }

            //Normal case, not on edges
            else
            {
//                //Check neighbors
//                if (cell_grid[i + 1][j] != NULL)
//                {
//                    //If alive, add TODO add conditional
//                    if (cell_grid[i + 1][j]->alive_ == true)
//                    {
//                        neighbor++;
//                    }
//                }
//                if (cell_grid[i - 1][j] != NULL)
//                {
//                    neighbor++;
//                }
//                if (cell_grid[i][j + 1] != NULL)
//                {
//                    neighbor++;
//                }
//                if (cell_grid[i][j - 1] != NULL)
//                {
//                    neighbor++;
//                }
//                if (cell_grid[i - 1][j - 1] != NULL)
//                {
//                    neighbor++;
//                }
//                if (cell_grid[i + 1][j + 1] != NULL)
//                {
//                    neighbor++;
//                }
//                if (cell_grid[i - 1][j + 1] != NULL)
//                {
//                    neighbor++;
//                }
//                if (cell_grid[i + 1][j - 1] != NULL)
//                {
//                    neighbor++;
//                }
            }
        }
    }
}
