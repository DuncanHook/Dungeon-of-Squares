#ifndef ENEMIES_H
#define ENEMIES_H


class enemies
{
public:
    enemies();

    void setPosition(unsigned int newColumn, unsigned int newRow);

    //movement stuff
    int column;
    int row;
    bool moved = false;

    //reset stuff
    int startingColumn;
    int startingRow;

    //combat stuff
    int health = 5;
    int currentTotal = 0;
    bool standing = false;
    bool critical = false;

    bool dead = false;
};

#endif // ENEMIES_H
