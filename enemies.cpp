#include "enemies.h"

enemies::enemies()
{

}

//setting the position of the enemy
void enemies::setPosition(unsigned int newColumn, unsigned int newRow)
{
    column = newColumn;
    row = newRow;

    startingColumn = newColumn;
    startingRow = newRow;

    return;
}
