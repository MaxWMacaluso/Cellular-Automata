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

    bool alive = false;

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
            }
            //Dead cell...
            else
            {
                cell_color = white;
                alive = false;
            }

            //Create a new cell
            Cell* newCell = new Cell(cell_color, j, i, alive);

            //Add each new cell in row to remp_row
            temp_row.push_back(newCell);

            scene->addItem(newCell);
        }

        //Once its gone through the whole row, add to final cell_grid
        cell_grid.push_back(temp_row);
    }
}
