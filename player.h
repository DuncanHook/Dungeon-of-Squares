#ifndef PLAYER_H
#define PLAYER_H


class player
{
public:
    player();

    void setPlayerPosition(unsigned int newColumn, unsigned int newRow);

    //movement stuff
    int column;
    int row;

    //reseting tiles stuff
    int startingColumn;
    int startingRow;

    //combat stuff
    int health = 20;
    int maxHealth = 40;
    int currentTotal = 0;
    bool standing = false;
    bool critical = false;

};

#endif // PLAYER_H
