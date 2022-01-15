#ifndef GAMEMAINWINDOW_H
#define GAMEMAINWINDOW_H

#include "enemies.h"
#include "player.h"

#include <QMainWindow>
#include <QString>
#include <QDebug>
#include <QTimer>
#include <QTime>
#include <QMessageBox>
#include <QMediaPlayer>

QT_BEGIN_NAMESPACE
namespace Ui { class GameMainWindow; }
QT_END_NAMESPACE

class GameMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    GameMainWindow(QWidget *parent = nullptr);
    ~GameMainWindow();

private slots:
    void on_playButton_clicked();

    void on_titleButton_clicked();

    void on_exitButton2_clicked();

    void on_exitButton1_clicked();

private:
    Ui::GameMainWindow *ui;

    QPalette playerColor;
    int highestScore = 0;
    int secondHighestScore = 0;
    int thirdHighestScore = 0;
    void leaderboardHandler(int score);
    //the timer that will trigger enemy movements
    QTimer *enemyMovement;

    //searches the floor for enemy markers and allocates them into the array.
    void setTiles();
    //resets the floor back to its original state.
    void resetTiles();

    //array of enemies on the floor
    enemies enemyIndex[10];
    //player coordinates
    player playerPosition;

    //keeping track of how many enemies are currently on the floor
    unsigned int enemyCount = 0;

    //keeps track of the floor for assignment purposes
    QString Floor = "one";
    //keeps track of if the player has reached the end and if they have they start going to random floors
    bool endReached = false;
    bool endReachedDisplayed = false;


    //currently for moving up floors, could be repurposed to random floor picking.
    void moveFloor();
     //required for switch statement during floor changing
    int floorNumber = 1;
    //just a tracker for fun to display to the player after  they have cleared all 3 floors for the first time
    int extraFloors = 0;

    //for development purposes, if true player will instantly roll crits in combat
    bool demoEngaged = false;


    //combat stuff
    void engageCombat(int enemy);
    void disengageCombat();
    void dealDamage();
    unsigned int engagedEnemy;

    //functions that will work in conjunction with moveEnemies, sequences say the order of the move direction functions.
    void sequenceZero(unsigned int i);
    void sequenceOne(unsigned int i);
    void sequenceTwo(unsigned int i);
    void sequenceThree(unsigned int i);

    void moveLeft(unsigned int i);
    void moveRight(unsigned int i);
    void moveDown(unsigned int i);
    void moveUp(unsigned int i);

    void keyPressEvent(QKeyEvent * event);

    QMediaPlayer * menuButtonSFX;
    QMediaPlayer * overworldUserSFX;
    QMediaPlayer * overworldUserBlockedSFX;
    QMediaPlayer * overworldNewFloorSFX;

    QMediaPlayer * battleUserIsHitDamageSFX;
    QMediaPlayer * battleHitEnemySFX;
    QMediaPlayer * battleHitButtonSFX;
    QMediaPlayer * battleCriticalHitSFX;
    QMediaPlayer * battleEnemyCriticalSFX;
    QMediaPlayer * battleTieSFX;
    QMediaPlayer * battleBustedUserSFX;
    QMediaPlayer * battleBustedEnemySFX;
    QMediaPlayer * battleStandingSFX;
    QMediaPlayer * battleLowHealthSFX;
    QMediaPlayer * battleReallyLowHealthSFX;
    QMediaPlayer * battleUserDeathSFX;
    QMediaPlayer * battleEnemyDeathSFX;
    QMediaPlayer * battleVictorySFX;

    QMediaPlayer * menuMusic;
    QMediaPlayer * menuGameOverMusic;
    QMediaPlayer * menuCreditsMusic;
    QMediaPlayer * overworldMusic;
    QMediaPlayer * overworldClearAllFloorsMusic;
    QMediaPlayer * battleMusic;

private slots:
    //made a slot so it can interact with the movement timer.
    void moveEnemies();

    void on_upButton1_3_clicked();
    void on_upButton1_clicked();
    void on_upButton1_4_clicked();
    void on_upButton1_2_clicked();
    void on_hitButton_clicked();
    void on_standBtn_clicked();
    void on_leaderboardButton2_clicked();
    void on_leaderboardButton1_clicked();
    void on_menuButtonFL_clicked();
    void on_creditsButton1_clicked();
    void on_titlButton2_clicked();
    void on_menuFCButton_clicked();
    void on_demoButton_clicked();
};
#endif // GAMEMAINWINDOW_H
