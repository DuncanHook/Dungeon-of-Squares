#include "player.h"

player::player()
{

}

void player::setPlayerPosition(unsigned int newColumn, unsigned int newRow)
{
    column = newColumn;
    row = newRow;

    startingColumn = newColumn;
    startingRow = newRow;

    return;
}
