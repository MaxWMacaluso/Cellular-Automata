#include "grid.h"
#include <stdlib.h>
#include <time.h>



//Constructor, randomely creates a grib of alive and dead cells
Grid::Grid(QGraphicsScene *scene, QGraphicsView *view)
{
    // create board... with lines and such
    int cellHeight = view->frameSize().height()-20;
    qDebug()<<cellHeight;
    int cellWidth = view->frameSize().width()-20;
    qDebug()<< cellWidth;
    for(int i = 0; i < view->frameSize().width(); i += (cellWidth/20)) {
            scene->addLine(i, 0, i, cellHeight);
    }
    for(int i = 0; i < view->frameSize().height(); i += (cellHeight/10)) {
            scene->addLine(0, i, cellWidth, i);
    }




    /* initialize random seed: */
    srand (time(NULL));

    /* generate secret number between 0 and 10: */

    int aliveProb;
    bool aliveBOOL;
    QColor green(Qt::green);
    QColor red(Qt::gray);
    QColor insert;
    for(int i =0;i<10;i++){
        for (int j=0;j<20;j++){
            aliveProb = rand() % 10;
            //qDebug() << aliveProb;
            if(aliveProb < 5){
                insert = green;
                aliveBOOL = true;
                //population_++;
            }
            else{
                insert = red;
                aliveBOOL = false;
            }
            Cell * newCell = new Cell(insert, j, i, aliveBOOL,cellWidth/20,cellHeight/10);
            //table[i][j] = newCell;
            scene->addItem(newCell);
        }
    }
}
