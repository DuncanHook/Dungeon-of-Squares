#include "gamemainwindow.h"
#include "ui_gamemainwindow.h"
#include <QMediaPlayer>
#include <QKeyEvent>

GameMainWindow::GameMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GameMainWindow),
      enemyMovement(new QTimer)
{
    ui->setupUi(this);
    //this messes with the background of the whole aplication
    //starts in the top left corner with the starting color (the color right after stop 0)
    //not sure what the stretch pad does so probably should not mess with it
    //this part actually changes the bacground --> "background: qlineargradient( x1:0 y1:0, x2:1 y2:0, stop:0 orange, stop:1 cyan);}");
    //the x1 and y1 is where the start color begins and should both be 0.
    //the x2 and y2 account for the direction of the color change from the first color to the second
    //thus if you have x2 and y2 both = 1 then you get a diagonal color shift from the left corner to the right corner.
    //alternatively if you have y2:1 and x2:0 you get a color shift from top to bottom

    //left
    ui->backgroundLabel->setStyleSheet("* {color: qlineargradient(spread:pad, x1:0 y1:0, x2:1 y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));"
                        "background: qlineargradient( x1:0 y1:0, x2:1 y2:0, stop:0 #4169E1, stop:1 orange);}");
    ui->backgroundLabel1->setStyleSheet("* {color: qlineargradient(spread:pad, x1:0 y1:0, x2:1 y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));"
                        "background: qlineargradient( x1:0 y1:0, x2:1 y2:0, stop:0 #4169E1, stop:1 orange);}");


    //middle
    ui->backgroundLabel_3->setStyleSheet("* {color: qlineargradient(spread:pad, x1:0 y1:0, x2:1 y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));"
                                         "background: qlineargradient( x1:0 y1:0, x2:1 y2:0, stop:0 orange, stop:1 #228B22);}");
    //right
    ui->backgroundLabel2->setStyleSheet("* {color: qlineargradient(spread:pad, x1:0 y1:0, x2:1 y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));"
                        "background: qlineargradient( x1:0 y1:0, x2:1 y2:0, stop:0 #228B22, stop:1 #FF6347);}");

    QPalette palette = ui->ruleslbl->palette();
    palette.setColor(ui->ruleslbl->foregroundRole(), Qt::white);
    ui->ruleslbl->setPalette(palette);

    palette = ui->label->palette();
    palette.setColor(ui->label->foregroundRole(), Qt::white);
    ui->label->setPalette(palette);

    palette = ui->currentHealthTitlelbl->palette();
    palette.setColor(ui->currentHealthTitlelbl->foregroundRole(), Qt::white);
    ui->currentHealthTitlelbl->setPalette(palette);

    palette = ui->enemyHealthTitlelbl->palette();
    palette.setColor(ui->enemyHealthTitlelbl->foregroundRole(), Qt::white);
    ui->enemyHealthTitlelbl->setPalette(palette);

    palette = ui->yourCurrentTotalTitlelbl->palette();
    palette.setColor(ui->yourCurrentTotalTitlelbl->foregroundRole(), Qt::white);
    ui->yourCurrentTotalTitlelbl->setPalette(palette);

    palette = ui->enemyCurrentTotalTitle->palette();
    palette.setColor(ui->enemyCurrentTotalTitle->foregroundRole(), Qt::white);
    ui->enemyCurrentTotalTitle->setPalette(palette);

    palette = ui->gameNameLabel->palette();
    palette.setColor(ui->gameNameLabel->foregroundRole(), Qt::white);
    ui->gameNameLabel->setPalette(palette);

    palette = ui->gameNameLabel_2->palette();
    palette.setColor(ui->gameNameLabel_2->foregroundRole(), Qt::white);
    ui->gameNameLabel_2->setPalette(palette);

    palette = ui->gameNameLabel_3->palette();
    palette.setColor(ui->gameNameLabel_3->foregroundRole(), Qt::white);
    ui->gameNameLabel_3->setPalette(palette);

    palette = ui->gameNameLabel_4->palette();
    palette.setColor(ui->gameNameLabel_4->foregroundRole(), Qt::white);
    ui->gameNameLabel_4->setPalette(palette);

    palette = ui->gameNameLabel_5->palette();
    palette.setColor(ui->gameNameLabel_5->foregroundRole(), Qt::white);
    ui->gameNameLabel_5->setPalette(palette);

    palette = ui->gameNameLabel_6->palette();
    palette.setColor(ui->gameNameLabel_6->foregroundRole(), Qt::white);
    ui->gameNameLabel_6->setPalette(palette);

    palette = ui->gameNameLabel_7->palette();
    palette.setColor(ui->gameNameLabel_7->foregroundRole(), Qt::white);
    ui->gameNameLabel_7->setPalette(palette);

    palette = ui->bestScore1_2->palette();
    palette.setColor(ui->bestScore1_2->foregroundRole(), Qt::white);
    ui->bestScore1_2->setPalette(palette);

    palette = ui->bestScore1_3->palette();
    palette.setColor(ui->bestScore1_3->foregroundRole(), Qt::white);
    ui->bestScore1_3->setPalette(palette);

    palette = ui->bestScore1_4->palette();
    palette.setColor(ui->bestScore1_4->foregroundRole(), Qt::white);
    ui->bestScore1_4->setPalette(palette);

    palette = ui->playerStandinglbl->palette();
    palette.setColor(ui->playerStandinglbl->foregroundRole(), Qt::white);
    ui->playerStandinglbl->setPalette(palette);

    palette = ui->enemyStandinglbl->palette();
    palette.setColor(ui->enemyStandinglbl->foregroundRole(), Qt::white);
    ui->enemyStandinglbl->setPalette(palette);

    palette = ui->getCloselbl->palette();
    palette.setColor(ui->getCloselbl->foregroundRole(), Qt::white);
    ui->getCloselbl->setPalette(palette);

    palette = ui->bustCritlbl->palette();
    palette.setColor(ui->bustCritlbl->foregroundRole(), Qt::white);
    ui->bustCritlbl->setPalette(palette);

    palette = ui->youlbl->palette();
    palette.setColor(ui->youlbl->foregroundRole(), Qt::white);
    ui->youlbl->setPalette(palette);

    palette = ui->youlbl_2->palette();
    palette.setColor(ui->youlbl_2->foregroundRole(), Qt::white);
    ui->youlbl_2->setPalette(palette);

    palette = ui->youlbl_3->palette();
    palette.setColor(ui->youlbl_3->foregroundRole(), Qt::white);
    ui->youlbl_3->setPalette(palette);

    palette = ui->youlbl_4->palette();
    palette.setColor(ui->youlbl_4->foregroundRole(), Qt::white);
    ui->youlbl_4->setPalette(palette);

    ui->gameBackgroundLabel-> setStyleSheet("background-color: rgb(255,255,255);");
    ui->gameSWidget->setCurrentIndex(0);
    ui->menuSWidget->setCurrentIndex(0);
    ui->buttonSWidget->setCurrentIndex(0);
    ui->demoOnlbl->setVisible(false);

    connect(enemyMovement, SIGNAL(timeout()),
            this, SLOT(moveEnemies()));

    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());

    playerColor = ui->one12->palette();

    ui->extraLabel->setVisible(false);
    ui->floorsClearedlbl->setVisible(false);

    ui->combatSWidget->setVisible(false);
    ui->combatSWidget->setEnabled(false);

    //SFX
    menuButtonSFX = new QMediaPlayer();
    menuButtonSFX->setMedia(QUrl("qrc:/Sound/SFX/menubutton.wav"));

    overworldUserSFX = new QMediaPlayer();
    overworldUserSFX->setMedia(QUrl("qrc:/Sound/SFX/movement.wav"));

    overworldUserBlockedSFX = new QMediaPlayer();
    overworldUserBlockedSFX->setMedia(QUrl("qrc:/Sound/SFX/blockedmovement.wav"));

    overworldNewFloorSFX = new QMediaPlayer();
    overworldNewFloorSFX->setMedia(QUrl("qrc:/Sound/SFX/newfloor.wav"));

    battleUserIsHitDamageSFX = new QMediaPlayer();
    battleUserIsHitDamageSFX->setMedia(QUrl("qrc:/Sound/SFX/damage.wav"));

    battleHitEnemySFX = new QMediaPlayer();
    battleHitEnemySFX->setMedia(QUrl("qrc:/Sound/SFX/hitenemy.wav"));

    battleHitButtonSFX = new QMediaPlayer();
    battleHitButtonSFX->setMedia(QUrl("qrc:/Sound/SFX/hitbutton.wav"));

    battleCriticalHitSFX = new QMediaPlayer();
    battleCriticalHitSFX->setMedia(QUrl("qrc:/Sound/SFX/criticalhit.wav"));

    battleEnemyCriticalSFX = new QMediaPlayer();
    battleEnemyCriticalSFX->setMedia(QUrl("qrc:/Sound/SFX/enemycrit.mp3"));

    battleTieSFX = new QMediaPlayer();
    battleTieSFX->setMedia(QUrl("qrc:/Sound/SFX/tiedamage.wav"));

    battleBustedUserSFX = new QMediaPlayer();
    battleBustedUserSFX->setMedia(QUrl("qrc:/Sound/SFX/busteduser.mp3"));

    battleBustedEnemySFX = new QMediaPlayer();
    battleBustedEnemySFX->setMedia(QUrl("qrc:/Sound/SFX/bustedenemy.mp3"));

    battleStandingSFX = new QMediaPlayer();
    battleStandingSFX->setMedia(QUrl("qrc:/Sound/SFX/standingbattle.wav"));

    battleLowHealthSFX = new QMediaPlayer();
    battleLowHealthSFX->setMedia(QUrl("qrc:/Sound/SFX/lowhealth.mp3"));

    battleReallyLowHealthSFX = new QMediaPlayer();
    battleReallyLowHealthSFX->setMedia(QUrl("qrc:/Sound/SFX/reallylowhealth.mp3"));

    battleUserDeathSFX = new QMediaPlayer();
    battleUserDeathSFX->setMedia(QUrl("qrc:/Sound/SFX/battleuserdeath.mp3"));

    battleEnemyDeathSFX = new QMediaPlayer();
    battleEnemyDeathSFX->setMedia(QUrl("qrc:/Sound/SFX/battleenemydeath.mp3"));

    battleVictorySFX = new QMediaPlayer();
    battleVictorySFX->setMedia(QUrl("qrc:/Sound/SFX/victory.mp3"));

    //start background music
    menuMusic = new QMediaPlayer();
    menuMusic->setMedia(QUrl("qrc:/Sound/Music/menu.mp3"));
    menuMusic->play();

    menuGameOverMusic = new QMediaPlayer();
    menuGameOverMusic->setMedia(QUrl("qrc:/Sound/Music/gameover.mp3"));

    menuCreditsMusic = new QMediaPlayer();
    menuCreditsMusic->setMedia(QUrl("qrc:/Sound/Music/creditsmusic.mp3"));

    overworldMusic = new QMediaPlayer();
    overworldMusic->setMedia(QUrl("qrc:/Sound/Music/overworld.mp3"));

    overworldClearAllFloorsMusic = new QMediaPlayer();
    overworldClearAllFloorsMusic->setMedia(QUrl("qrc:/Sound/Music/clearfloorsvictory.mp3"));

    battleMusic = new QMediaPlayer();
    battleMusic->setMedia(QUrl("qrc:/Sound/Music/battle.mp3"));

    menuButtonSFX->setVolume(30);
    overworldUserSFX->setVolume(40);
    overworldUserBlockedSFX->setVolume(30);
    overworldNewFloorSFX->setVolume(30);
    battleUserIsHitDamageSFX->setVolume(30);
    battleHitEnemySFX->setVolume(30);
    battleHitButtonSFX->setVolume(30);
    battleCriticalHitSFX->setVolume(25);
    battleEnemyCriticalSFX->setVolume(30);
    battleTieSFX->setVolume(30);
    battleBustedUserSFX->setVolume(30);
    battleBustedEnemySFX->setVolume(30);
    battleStandingSFX->setVolume(30);
    battleLowHealthSFX->setVolume(40);
    battleReallyLowHealthSFX->setVolume(40);
    battleUserDeathSFX->setVolume(40);
    battleEnemyDeathSFX->setVolume(30);
    battleVictorySFX->setVolume(40);

    menuMusic->setVolume(40);
    menuGameOverMusic->setVolume(40);
    menuCreditsMusic->setVolume(45);
    overworldMusic->setVolume(40);
    overworldClearAllFloorsMusic->setVolume(40);
    battleMusic->setVolume(40);

}

GameMainWindow::~GameMainWindow()
{
    delete ui;
}

void GameMainWindow::keyPressEvent(QKeyEvent *event)
{
    if (menuMusic->state() == QMediaPlayer::PlayingState) {
        if(event->key() == Qt::Key_R) {
            ui->playButton->animateClick();
        }
    }
    else if (menuMusic->state() == QMediaPlayer::StoppedState) {
        if(event->key() == Qt::Key_W) {
            ui->upButton1->animateClick();
        }
        if(event->key() == Qt::Key_A) {
            ui->upButton1_4->animateClick();
        }
        if(event->key() == Qt::Key_S) {
            ui->upButton1_2->animateClick();
        }
        if(event->key() == Qt::Key_D) {
            ui->upButton1_3->animateClick();
        }
    }

    if (battleMusic->state() == QMediaPlayer::PlayingState) {
        if(event->key() == Qt::Key_Q) {
            ui->hitButton->animateClick();
        }
        if(event->key() == Qt::Key_E) {
            ui->standBtn->animateClick();
        }
    }
    else if (battleMusic->state() == QMediaPlayer::StoppedState) {
        //nothing
    }

}

void GameMainWindow::on_playButton_clicked()
{
    menuButtonSFX->play();
    menuMusic->stop();

    ui->gameSWidget->setCurrentIndex(1);
    ui->menuSWidget->setCurrentIndex(1);
    ui->buttonSWidget->setCurrentIndex(1);

    //reset variables incase the user returned to the menue and restarted the game.
    enemyCount = 0;
    Floor = "one";
    //find and allocate enemys on our grid
    setTiles();
    qDebug() << enemyCount;

    //start enemies moving
    enemyMovement->start(1000);

    overworldMusic->play();

}


void GameMainWindow::on_titleButton_clicked()
{
    overworldMusic->stop();
    menuMusic->play();
    leaderboardHandler(extraFloors);
    ui->gameSWidget->setCurrentIndex(0);
    ui->menuSWidget->setCurrentIndex(0);
    ui->buttonSWidget->setCurrentIndex(0);

    enemyMovement->stop();

    ui->extraLabel->setVisible(false);
    ui->floorsClearedlbl->setVisible(false);
    extraFloors = 0;

    resetTiles();
    endReached = false;
    playerPosition.health = 20;
    Floor = "one";
    floorNumber = 1;
}

void GameMainWindow::on_exitButton2_clicked()
{
    QApplication::quit();
}

void GameMainWindow::on_exitButton1_clicked()
{
    QApplication::quit();
}

//setTiles Searches our grid for the distinguisher of enemies and then saves their position to the array of enemies.
void GameMainWindow::setTiles()
{
    // i = columns j = rows
    for(unsigned int i = 1; i <= 10; i ++){
        for(unsigned int j = 1; j <= 8; j ++){
            //create the name for the proper label to scan for enemies.
            QString iConverted = QString::number(i);
            QString jConverted = QString::number(j);
            QString UI = (Floor + iConverted + jConverted);

            //find the Label we are looking for and check its color
            QLabel * lbl = this->findChild<QLabel*>(UI);
            QColor color = lbl->palette().text().color();

            if(color =="yellow" ){
                enemyIndex[enemyCount].setPosition(i,j);
                enemyCount++;
            }

            if (color =="green"){
                qDebug() << "found player";

                playerPosition.setPlayerPosition(i,j);
            }
        }
    }
}

void GameMainWindow::resetTiles()
{
    //set a current lbl identifier for player
    QString UI = Floor + QString::number(playerPosition.column) + QString::number(playerPosition.row);
    QLabel * currentlbl = this->findChild<QLabel*>(UI);


    //find label that the player space will be moving to
    UI = Floor + (QString::number(playerPosition.startingColumn)) + (QString::number(playerPosition.startingRow));
    QLabel * movelbl = this->findChild<QLabel*>(UI);

    currentlbl->setStyleSheet("background-color: white;\ncolor: white;\nborder: 1px solid #555;\n");
    currentlbl->setPalette(ui->openSpaceKey->palette());

    movelbl->setStyleSheet("background-color: green;\ncolor: green;\nborder: 1px solid #555;");
    movelbl->setPalette(ui->playerKey->palette());

    //reset enemy spaces
    for(unsigned int i = 0; i < enemyCount; i++){
        enemyIndex[i].dead = false;

        bool onStarting = false;
        //set a current lbl identifier

        QString EUI = Floor + QString::number(enemyIndex[i].column) + QString::number(enemyIndex[i].row);
        QLabel * currentlbl = this->findChild<QLabel*>(EUI);


        //find label that the enemy will be moving to.
        EUI = Floor + (QString::number(enemyIndex[i].startingColumn)) + (QString::number(enemyIndex[i].startingRow));
        QLabel * movelbl = this->findChild<QLabel*>(EUI);

        for(unsigned int j = 0; j< enemyCount; j++){
            QString startingCheck = Floor + (QString::number(enemyIndex[j].startingColumn)) + (QString::number(enemyIndex[j].startingRow));
            QString positionCheck = Floor + QString::number(enemyIndex[i].column) + QString::number(enemyIndex[i].row);

            if (startingCheck == positionCheck)
                onStarting = true;

        }

        if (onStarting == false){
        currentlbl->setStyleSheet("background-color: white;\ncolor:white;\nborder: 1px solid #555;\n");
        currentlbl->setPalette(ui->openSpaceKey->palette());
        }

        movelbl->setStyleSheet("background-color: rgb(255, 255, 0);\ncolor: yellow;\nborder: 1px solid #555;");
        movelbl->setPalette(ui->enemyKey->palette());
    }
    enemyCount = 0;

}

void GameMainWindow::moveFloor()
{
    //player health regen
    playerPosition.health += 10;
    if (playerPosition.health > playerPosition.maxHealth)
        playerPosition.health = playerPosition.maxHealth;

    //sound stuff
    if (floorNumber == 3 && endReached == false) {
        //do nothing, initial 3rd floor clear
    } else {
        overworldNewFloorSFX->play();

    }

    enemyMovement->stop();
    resetTiles();

    if (floorNumber == 3)
        endReached = true;

    if(endReached == false){

    switch(floorNumber){
    case 1 :
        Floor = "two";
        floorNumber = 2;
        break;
    case 2 :
        Floor = "three";
        floorNumber = 3;
        break;
    }
  }



    else{
        if (endReachedDisplayed == true)
            extraFloors++;

        ui->floorsClearedlbl->setText(QString::number(extraFloors));

        if (endReachedDisplayed == false){
            overworldMusic->stop();
            overworldClearAllFloorsMusic->play();

            QMessageBox msgBox;
            msgBox.setText("You have reached the end! \n You will now randomly go through floors again!\n see how many you can clear!");
            msgBox.setWindowTitle("Congratulations!");
            msgBox.exec();

            ui->extraLabel->setVisible(true);
            ui->floorsClearedlbl->setVisible(true);

            endReachedDisplayed = true;
            overworldClearAllFloorsMusic->stop();
            overworldNewFloorSFX->play();
            overworldMusic->play();
        }

        int randomFloor = 1 + qrand() % ((3+1)-1);


        while (randomFloor == floorNumber)
            randomFloor = 1 + qrand() % ((3+1)-1);

        switch(randomFloor){
        case 1 :
            Floor = "one";
            floorNumber = 1;
            break;
        case 2 :
            Floor = "two";
            floorNumber = 2;
            break;
        case 3 :
            Floor = "three";
            floorNumber = 3;
            break;
        }
    }
    ui->gameSWidget->setCurrentIndex(floorNumber);

    setTiles();
    enemyMovement->start(1000);
}

void GameMainWindow::engageCombat(int enemy)
{
    enemyMovement->stop();
    engagedEnemy = enemy;

    ui->gameSWidget->setVisible(false);
    ui->menuSWidget->setVisible(false);
    ui->buttonSWidget->setVisible(false);
    ui->keysBox->setVisible(false);
    ui->backgroundLabel->setVisible(false);
    ui->extraLabel->setVisible(false);
    ui->floorsClearedlbl->setVisible(false);


    ui->gameSWidget->setEnabled(false);
    ui->menuSWidget->setEnabled(false);
    ui->buttonSWidget->setEnabled(false);
    ui->keysBox->setEnabled(false);
    ui->backgroundLabel->setEnabled(false);

    ui->playerStandinglbl->setVisible(false);
    ui->enemyStandinglbl->setVisible(false);
    ui->bustCritlbl->setVisible(false);
    ui->combatSWidget->setVisible(true);
    ui->combatSWidget->setEnabled(true);

    playerPosition.currentTotal = 0;
    enemyIndex[engagedEnemy].currentTotal = 0;
    enemyIndex[engagedEnemy].health = 5;

    ui->currentHealthlbl->setText(QString::number(playerPosition.health));
    ui->enemyHealthlbl->setText(QString::number(enemyIndex[engagedEnemy].health));

    overworldMusic->stop();
    battleMusic->play();

    if(playerPosition.health <= 1) {
        if (battleReallyLowHealthSFX->state() == QMediaPlayer::PlayingState) {
            battleReallyLowHealthSFX->setPosition(0);
        }
        else if (battleReallyLowHealthSFX->state() == QMediaPlayer::StoppedState) {
            battleReallyLowHealthSFX->play();
        }
        if (battleLowHealthSFX->state() == QMediaPlayer::PlayingState) {
            battleLowHealthSFX->stop();
            battleReallyLowHealthSFX->setPosition(0);
        }
    } else if(playerPosition.health <= 5) {
        if (battleLowHealthSFX->state() == QMediaPlayer::PlayingState) {
            battleLowHealthSFX->setPosition(0);
        }
        else if (battleLowHealthSFX->state() == QMediaPlayer::StoppedState) {
            battleLowHealthSFX->play();
        }
    }
}

void GameMainWindow::disengageCombat()
{

    ui->playerStandinglbl->setVisible(false);
    ui->enemyStandinglbl->setVisible(false);
    ui->combatSWidget->setVisible(false);
    ui->combatSWidget->setEnabled(false);

    ui->gameSWidget->setVisible(true);
    ui->menuSWidget->setVisible(true);
    ui->buttonSWidget->setVisible(true);
    ui->keysBox->setVisible(true);
    ui->backgroundLabel->setVisible(true);

    if(endReached==true){
    ui->extraLabel->setVisible(true);
    ui->floorsClearedlbl->setVisible(true);
    }

    ui->gameSWidget->setEnabled(true);
    ui->menuSWidget->setEnabled(true);
    ui->buttonSWidget->setEnabled(true);
    ui->keysBox->setEnabled(true);
    ui->backgroundLabel->setEnabled(true);

    playerPosition.currentTotal = 0;
    enemyIndex[engagedEnemy].currentTotal = 0;

    //set a current lbl identifier for player
    QString UI = Floor + QString::number(playerPosition.column) + QString::number(playerPosition.row);
    QLabel * currentlbl = this->findChild<QLabel*>(UI);


    //find label that the player space will be moving to
    UI = Floor + (QString::number(enemyIndex[engagedEnemy].column)) + (QString::number(enemyIndex[engagedEnemy].row));
    QLabel * movelbl = this->findChild<QLabel*>(UI);

    currentlbl->setStyleSheet("background-color: white;\ncolor: white;\nborder: 1px solid #555;\n");
    currentlbl->setPalette(ui->openSpaceKey->palette());

    movelbl->setStyleSheet("background-color: green;\ncolor: green;\nborder: 1px solid #555;");
    movelbl->setPalette(ui->playerKey->palette());
    playerPosition.column = enemyIndex[engagedEnemy].column;
    playerPosition.row = enemyIndex[engagedEnemy].row;

    enemyMovement->start(1000);
}

void GameMainWindow::dealDamage()
{
    QMessageBox msgBox;
    int damage = 0;

    //enemy deals damage to you
    if (enemyIndex[engagedEnemy].currentTotal > playerPosition.currentTotal){
        damage = (enemyIndex[engagedEnemy].currentTotal - playerPosition.currentTotal);

        if (enemyIndex[engagedEnemy].critical == true){
            damage++;
            ui->bustCritlbl->setText("Critical Hit!");
            ui->bustCritlbl->setVisible("true");
        }

        playerPosition.health -= damage;

        qDebug() << "player health is " << playerPosition.health;

        if(playerPosition.health <= 1) {
            if (battleReallyLowHealthSFX->state() == QMediaPlayer::PlayingState) {
                battleReallyLowHealthSFX->setPosition(0);
            }
            else if (battleReallyLowHealthSFX->state() == QMediaPlayer::StoppedState) {
                battleReallyLowHealthSFX->play();
            }
            if (battleLowHealthSFX->state() == QMediaPlayer::PlayingState) {
                battleLowHealthSFX->stop();
                battleReallyLowHealthSFX->setPosition(0);
            }
        } else if(playerPosition.health <= 5) {
            if (battleLowHealthSFX->state() == QMediaPlayer::PlayingState) {
                battleLowHealthSFX->setPosition(0);
            }
            else if (battleLowHealthSFX->state() == QMediaPlayer::StoppedState) {
                battleLowHealthSFX->play();
            }
        }

        if(playerPosition.health <= 0) {
            battleMusic->stop();
            battleLowHealthSFX->stop();
            battleReallyLowHealthSFX->stop();

            if (battleUserDeathSFX->state() == QMediaPlayer::PlayingState) {
                battleUserDeathSFX->setPosition(0);
            }
            else if (battleUserDeathSFX->state() == QMediaPlayer::StoppedState) {
                battleUserDeathSFX->play();
            }
        }

        ui->currentHealthlbl->setText(QString::number(playerPosition.health));

        if(enemyIndex[engagedEnemy].critical == true){
            if (battleEnemyCriticalSFX->state() == QMediaPlayer::PlayingState) {
                battleEnemyCriticalSFX->setPosition(0);
            }
            else if (battleEnemyCriticalSFX->state() == QMediaPlayer::StoppedState) {
                battleEnemyCriticalSFX->play();
            }
            msgBox.setText("The enemy landed a critical hit!\nYou took " + QString::number(damage) + " damage");
            msgBox.setWindowTitle("Damage Dealt");
            msgBox.exec();
        }

        else {
            if (battleUserIsHitDamageSFX->state() == QMediaPlayer::PlayingState) {
                battleUserIsHitDamageSFX->setPosition(0);
            }
            else if (battleUserIsHitDamageSFX->state() == QMediaPlayer::StoppedState) {
                battleUserIsHitDamageSFX->play();
            }

            msgBox.setText("You took " + QString::number(damage) + " damage");
            msgBox.setWindowTitle("Damage Dealt");
            msgBox.exec();
        }
    }

    //you damage enemy
    if (enemyIndex[engagedEnemy].currentTotal < playerPosition.currentTotal){     
        damage = (playerPosition.currentTotal - enemyIndex[engagedEnemy].currentTotal );
        if(playerPosition.critical == true){
            if (battleCriticalHitSFX->state() == QMediaPlayer::PlayingState) {
                battleCriticalHitSFX->setPosition(0);
            }
            else if (battleCriticalHitSFX->state() == QMediaPlayer::StoppedState) {
                battleCriticalHitSFX->play();
            }

            damage++;
            ui->bustCritlbl->setText("Critical Hit!");
            ui->bustCritlbl->setVisible("true");
        } else {
            if (battleHitEnemySFX->state() == QMediaPlayer::PlayingState) {
                battleHitEnemySFX->setPosition(0);
            }
            else if (battleHitEnemySFX->state() == QMediaPlayer::StoppedState) {
                battleHitEnemySFX->play();
            }
        }

        enemyIndex[engagedEnemy].health -= damage;

        if(enemyIndex[engagedEnemy].health <= 0) {
            if (battleEnemyDeathSFX->state() == QMediaPlayer::PlayingState) {
                battleEnemyDeathSFX->setPosition(0);
            }
            else if (battleEnemyDeathSFX->state() == QMediaPlayer::StoppedState) {
                battleEnemyDeathSFX->play();
            }
        }

        qDebug() << "enemy health is " << enemyIndex[engagedEnemy].health;

        ui->enemyHealthlbl->setText(QString::number(enemyIndex[engagedEnemy].health));

        if(playerPosition.critical == true){
            msgBox.setText("Critical Hit!\nYou dealt " + QString::number(damage) + " damage");
            msgBox.setWindowTitle("Damage Dealt");
            msgBox.exec();
        }

        else {
            msgBox.setText("You dealt " + QString::number(damage) + " damage");
            msgBox.setWindowTitle("Damage Dealt");
            msgBox.exec();
        }
    }

    //tie, no damage
    if (enemyIndex[engagedEnemy].currentTotal == playerPosition.currentTotal){
        if (battleTieSFX->state() == QMediaPlayer::PlayingState) {
            battleTieSFX->setPosition(0);
        }
        else if (battleTieSFX->state() == QMediaPlayer::StoppedState) {
            battleTieSFX->play();
        }

        msgBox.setText("Tied result: no damage dealt or taken.");
        msgBox.setWindowTitle("Damage Dealt");
        msgBox.exec();
    }

    if (enemyIndex[engagedEnemy].health <= 0){
        battleMusic->stop();
        battleLowHealthSFX->stop();
        battleReallyLowHealthSFX->stop();
        battleVictorySFX->play();
        msgBox.setText("You won the combat!");
        msgBox.setWindowTitle("Victory");
        msgBox.exec();

        enemyIndex[engagedEnemy].dead = true;

        disengageCombat();

        battleVictorySFX->stop();
        battleEnemyDeathSFX->stop();
        battleCriticalHitSFX->stop();
        battleHitEnemySFX->stop();

        overworldMusic->play();

    }

    //player dies

    if (playerPosition.health <= 0){
        battleMusic->stop();

        leaderboardHandler(extraFloors);
        disengageCombat();

        ui->gameSWidget->setCurrentIndex(0);
        ui->menuSWidget->setCurrentIndex(0);
        ui->buttonSWidget->setCurrentIndex(0);

        enemyMovement->stop();

        battleMusic->stop();
        battleEnemyDeathSFX->stop();
        battleLowHealthSFX->stop();
        battleReallyLowHealthSFX->stop();
        menuGameOverMusic->play();

        ui->extraLabel->setVisible(false);
        ui->floorsClearedlbl->setVisible(false);
        extraFloors = 0;


        endReached = false;
        resetTiles();
        Floor = "one";
        floorNumber = 1;

        msgBox.setText("You lost and have been returned to title screen! Do try again!");
        msgBox.setWindowTitle("Defeat");
        msgBox.exec();

        playerPosition.health = 20;

        battleUserDeathSFX->stop();
        menuMusic->play();
    }

    ui->hitButton->setEnabled(true);
    ui->standBtn->setEnabled(true);
    ui->playerStandinglbl->setVisible(false);
    ui->enemyStandinglbl->setVisible(false);

    playerPosition.currentTotal = 0;
    enemyIndex[engagedEnemy].currentTotal = 0;

    playerPosition.standing = false;
    enemyIndex[engagedEnemy].standing = false;

    playerPosition.critical = false;
    enemyIndex[engagedEnemy].critical = false;

    ui->bustCritlbl->setVisible(false);

    ui->yourTotallbl->setText(QString::number(playerPosition.currentTotal));
    ui->enemyTotallbl->setText(QString::number(enemyIndex[engagedEnemy].currentTotal));


}

void GameMainWindow::sequenceZero(unsigned int i)
{
    enemyIndex[i].moved = false;

    if(enemyIndex[i].column != 1 && enemyIndex[i].moved != true)
        moveLeft(i);

    if(enemyIndex[i].row != 8 && enemyIndex[i].moved != true)
        moveDown(i);

    if(enemyIndex[i].column != 10 && enemyIndex[i].moved != true)
        moveRight(i);

    if(enemyIndex[i].row != 1 && enemyIndex[i].moved != true)
        moveUp(i);
}

void GameMainWindow::sequenceOne(unsigned int i)
{
    enemyIndex[i].moved = false;

    if(enemyIndex[i].row != 8 && enemyIndex[i].moved != true)
        moveDown(i);

    if(enemyIndex[i].column != 10 && enemyIndex[i].moved != true)
        moveRight(i);

    if(enemyIndex[i].row != 1 && enemyIndex[i].moved != true)
        moveUp(i);

    if(enemyIndex[i].column != 1 && enemyIndex[i].moved != true)
        moveLeft(i);
}

void GameMainWindow::sequenceTwo(unsigned int i)
{
    enemyIndex[i].moved = false;

    if(enemyIndex[i].column != 10 && enemyIndex[i].moved != true)
        moveRight(i);

    if(enemyIndex[i].row != 1 && enemyIndex[i].moved != true)
        moveUp(i);

    if(enemyIndex[i].column != 1 && enemyIndex[i].moved != true)
        moveLeft(i);

    if(enemyIndex[i].row != 8 && enemyIndex[i].moved != true)
        moveDown(i);
}

void GameMainWindow::sequenceThree(unsigned int i)
{
    enemyIndex[i].moved = false;

    if(enemyIndex[i].row != 1 && enemyIndex[i].moved != true)
        moveUp(i);

    if(enemyIndex[i].column != 1 && enemyIndex[i].moved != true)
        moveLeft(i);

    if(enemyIndex[i].row != 8 && enemyIndex[i].moved != true)
        moveDown(i);

    if(enemyIndex[i].column != 10 && enemyIndex[i].moved != true)
        moveRight(i);
}

void GameMainWindow::moveLeft(unsigned int i)
{
    //set a current lbl identifier

    QString UI = Floor + QString::number(enemyIndex[i].column) + QString::number(enemyIndex[i].row);
    QLabel * currentlbl = this->findChild<QLabel*>(UI);

    QPalette Yellow = currentlbl->palette();

    //find label that the enemy will be moving to.
    UI = Floor + QString::number((enemyIndex[i].column - 1)) + QString::number(enemyIndex[i].row);
    QLabel * movelbl = this->findChild<QLabel*>(UI);
    QColor color = movelbl->palette().text().color();

    if (color == "white"){

    QPalette white = movelbl->palette();

    currentlbl->setStyleSheet("background-color: white;\ncolor:white;\nborder: 1px solid #555;\n");
    currentlbl->setPalette(white);

    movelbl->setStyleSheet("background-color: rgb(255, 255, 0);\ncolor: yellow;\nborder: 1px solid #555;");
    movelbl->setPalette(Yellow);


    enemyIndex[i].column --;

    enemyIndex[i].moved = true;
    }

    if (color == "green"){
        engageCombat(i);
    }


}

void GameMainWindow::moveRight(unsigned int i)
{
    //set a current lbl identifier

    QString UI = Floor + QString::number(enemyIndex[i].column) + QString::number(enemyIndex[i].row);
    QLabel * currentlbl = this->findChild<QLabel*>(UI);

    QPalette Yellow = currentlbl->palette();

    //find label that the enemy will be moving to.
    UI = Floor + (QString::number(enemyIndex[i].column+1)) + (QString::number(enemyIndex[i].row));
    QLabel * movelbl = this->findChild<QLabel*>(UI);
    QColor color = movelbl->palette().text().color();

    if (color == "white"){
    QPalette white = movelbl->palette();


    currentlbl->setStyleSheet("background-color: white;\ncolor:white;\nborder: 1px solid #555;\n");
    currentlbl->setPalette(white);

    movelbl->setStyleSheet("background-color: rgb(255, 255, 0);\ncolor: yellow;\nborder: 1px solid #555;");
    movelbl->setPalette(Yellow);

    enemyIndex[i].column++;

    enemyIndex[i].moved = true;
    }

    if (color == "green"){
        engageCombat(i);
    }

}

void GameMainWindow::moveDown(unsigned int i)
{
    //set a current lbl identifier

    QString UI = Floor + QString::number(enemyIndex[i].column) + QString::number(enemyIndex[i].row);
    QLabel * currentlbl = this->findChild<QLabel*>(UI);

    QPalette Yellow = currentlbl->palette();

    //find label that the enemy will be moving to.
    UI = Floor + QString::number((enemyIndex[i].column)) + (QString::number(enemyIndex[i].row +1));
    QLabel * movelbl = this->findChild<QLabel*>(UI);
    QColor color = movelbl->palette().text().color();

    if (color == "white"){

    QPalette white = movelbl->palette();

    currentlbl->setStyleSheet("background-color: white;\ncolor:white;\nborder: 1px solid #555;\n");
    currentlbl->setPalette(white);

    movelbl->setStyleSheet("background-color: rgb(255, 255, 0);\ncolor: yellow;\nborder: 1px solid #555;");
    movelbl->setPalette(Yellow);


     enemyIndex[i].row ++;

    enemyIndex[i].moved = true;
    }

    if (color == "green"){
        engageCombat(i);
    }


}

void GameMainWindow::moveUp(unsigned int i)
{
    //set a current lbl identifier

    QString UI = Floor + QString::number(enemyIndex[i].column) + QString::number(enemyIndex[i].row);
    QLabel * currentlbl = this->findChild<QLabel*>(UI);

    QPalette Yellow = currentlbl->palette();

    //find label that the enemy will be moving to.
    UI = Floor + QString::number((enemyIndex[i].column)) + QString::number((enemyIndex[i].row - 1));
    QLabel * movelbl = this->findChild<QLabel*>(UI);
    QColor color = movelbl->palette().text().color();

    if (color == "white"){
    QPalette white = movelbl->palette();

    currentlbl->setStyleSheet("background-color: white;\ncolor:white;\nborder: 1px solid #555;\n");
    currentlbl->setPalette(white);

    movelbl->setStyleSheet("background-color: rgb(255, 255, 0);\ncolor: yellow;\nborder: 1px solid #555;");
    movelbl->setPalette(Yellow);

    enemyIndex[i].row --;

    enemyIndex[i].moved = true;
    }

    if (color == "green"){
        engageCombat(i);
    }

}





void GameMainWindow::moveEnemies()
{
        for(unsigned int i = 0; i < enemyCount; i++){
             if(enemyIndex[i].dead == false){

        int randomValue = qrand() % 4;

        if(randomValue == 0 )
            sequenceZero(i);

        else if(randomValue == 1)
            sequenceOne(i);

        else if(randomValue == 2)
            sequenceTwo(i);

        else if(randomValue == 3)
            sequenceThree(i);
    }
        }

}

void GameMainWindow::on_upButton1_3_clicked()
{
    QString PUI = Floor + QString::number(playerPosition.column) + QString::number(playerPosition.row);
    QLabel * currentlbl = this->findChild<QLabel*>(PUI);

    QPalette Green = currentlbl->palette();

    PUI = Floor + QString::number(playerPosition.column + 1) + QString::number(playerPosition.row);

    QLabel * movelbl = this->findChild<QLabel*>(PUI);
    QColor color = movelbl->palette().text().color();

    if (color == "white"){
    QPalette white = movelbl->palette();

    currentlbl->setStyleSheet("background-color: white;\ncolor: white;\nborder: 1px solid #555;\n");
    currentlbl->setPalette(white);

    movelbl->setStyleSheet("background-color: green;\ncolor: green;\nborder: 1px solid #555;");
    movelbl->setPalette(Green);

    if (overworldUserSFX->state() == QMediaPlayer::PlayingState) {
        overworldUserSFX->setPosition(0);
    }
    else if (overworldUserSFX->state() == QMediaPlayer::StoppedState) {
        overworldUserSFX->play();
    }

    playerPosition.column++;
    }

    if (color == "red"){
        moveFloor();
    }

    if (color == "yellow"){
        for (unsigned int i = 0; i < enemyCount; i++){
            QString enemyCheck = Floor + QString::number(enemyIndex[i].column) + QString::number(enemyIndex[i].row);

            if(enemyCheck == PUI)
                engageCombat(i);
        }
    }

    if (color == "black") {
        if (overworldUserBlockedSFX->state() == QMediaPlayer::PlayingState) {
            overworldUserBlockedSFX->setPosition(0);
        }
        else if (overworldUserBlockedSFX->state() == QMediaPlayer::StoppedState) {
            overworldUserBlockedSFX->play();
        }
    }

}

void GameMainWindow::on_upButton1_clicked()
{
    QString PUI = Floor + QString::number(playerPosition.column) + QString::number(playerPosition.row);
    QLabel * currentlbl = this->findChild<QLabel*>(PUI);

    QPalette Green = currentlbl->palette();

    PUI = Floor + QString::number(playerPosition.column) + QString::number(playerPosition.row - 1);

    QLabel * movelbl = this->findChild<QLabel*>(PUI);
    QColor color = movelbl->palette().text().color();

    if (color == "white"){
    QPalette white = movelbl->palette();

    currentlbl->setStyleSheet("background-color: white;\ncolor: white;\nborder: 1px solid #555;\n");
    currentlbl->setPalette(white);

    movelbl->setStyleSheet("background-color: green;\ncolor: green;\nborder: 1px solid #555;");
    movelbl->setPalette(Green);

    if (overworldUserSFX->state() == QMediaPlayer::PlayingState) {
        overworldUserSFX->setPosition(0);
    }
    else if (overworldUserSFX->state() == QMediaPlayer::StoppedState) {
        overworldUserSFX->play();
    }

    playerPosition.row--;
    }

    if (color == "red"){
        moveFloor();
    }

    if (color == "yellow"){
        for (unsigned int i = 0; i < enemyCount; i++){
            QString enemyCheck = Floor + QString::number(enemyIndex[i].column) + QString::number(enemyIndex[i].row);

            if(enemyCheck == PUI)
                engageCombat(i);
        }
    }

    if (color == "black") {
        if (overworldUserBlockedSFX->state() == QMediaPlayer::PlayingState) {
            overworldUserBlockedSFX->setPosition(0);
        }
        else if (overworldUserBlockedSFX->state() == QMediaPlayer::StoppedState) {
            overworldUserBlockedSFX->play();
        }
    }

}

void GameMainWindow::on_upButton1_4_clicked()
{
    if (playerPosition.column == 1) {
        return;
    }
    QString PUI = Floor + QString::number(playerPosition.column) + QString::number(playerPosition.row);
    QLabel * currentlbl = this->findChild<QLabel*>(PUI);

    QPalette Green = currentlbl->palette();

    PUI = Floor + QString::number(playerPosition.column - 1) + QString::number(playerPosition.row);

    QLabel * movelbl = this->findChild<QLabel*>(PUI);
    QColor color = movelbl->palette().text().color();

    if (color == "white"){
    QPalette white = movelbl->palette();

    currentlbl->setStyleSheet("background-color: white;\ncolor: white;\nborder: 1px solid #555;\n");
    currentlbl->setPalette(white);

    movelbl->setStyleSheet("background-color: green;\ncolor: green;\nborder: 1px solid #555;");
    movelbl->setPalette(Green);

    if (overworldUserSFX->state() == QMediaPlayer::PlayingState) {
        overworldUserSFX->setPosition(0);
    }
    else if (overworldUserSFX->state() == QMediaPlayer::StoppedState) {
        overworldUserSFX->play();
    }

    playerPosition.column--;
    }

    if (color == "red"){
        moveFloor();
    }

    if (color == "yellow"){
        for (unsigned int i = 0; i < enemyCount; i++){
            QString enemyCheck = Floor + QString::number(enemyIndex[i].column) + QString::number(enemyIndex[i].row);

            if(enemyCheck == PUI)
                engageCombat(i);
        }
    }

    if (color == "black") {
        if (overworldUserBlockedSFX->state() == QMediaPlayer::PlayingState) {
            overworldUserBlockedSFX->setPosition(0);
        }
        else if (overworldUserBlockedSFX->state() == QMediaPlayer::StoppedState) {
            overworldUserBlockedSFX->play();
        }
    }

}

void GameMainWindow::on_upButton1_2_clicked()
{
    QString PUI = Floor + QString::number(playerPosition.column) + QString::number(playerPosition.row);
    QLabel * currentlbl = this->findChild<QLabel*>(PUI);

    QPalette Green = currentlbl->palette();

    PUI = Floor + QString::number(playerPosition.column) + QString::number(playerPosition.row + 1);

    QLabel * movelbl = this->findChild<QLabel*>(PUI);
    QColor color = movelbl->palette().text().color();

    if (color == "white"){
    QPalette white = movelbl->palette();

    currentlbl->setStyleSheet("background-color: white;\ncolor: white;\nborder: 1px solid #555;\n");
    currentlbl->setPalette(white);

    movelbl->setStyleSheet("background-color: green;\ncolor: green;\nborder: 1px solid #555;");
    movelbl->setPalette(Green);

    if (overworldUserSFX->state() == QMediaPlayer::PlayingState) {
        overworldUserSFX->setPosition(0);
    }
    else if (overworldUserSFX->state() == QMediaPlayer::StoppedState) {
        overworldUserSFX->play();
    }

    playerPosition.row++;
    }

    if (color == "red"){
        moveFloor();
    }

    if (color == "yellow"){
        for (unsigned int i = 0; i < enemyCount; i++){
            QString enemyCheck = Floor + QString::number(enemyIndex[i].column) + QString::number(enemyIndex[i].row);

            if(enemyCheck == PUI)
                engageCombat(i);
        }
    }

    if (color == "black") {
        if (overworldUserBlockedSFX->state() == QMediaPlayer::PlayingState) {
            overworldUserBlockedSFX->setPosition(0);
        }
        else if (overworldUserBlockedSFX->state() == QMediaPlayer::StoppedState) {
            overworldUserBlockedSFX->play();
        }
    }
}

void GameMainWindow::on_hitButton_clicked()
{    
    ui->hitButton->setEnabled(false);
    ui->standBtn->setEnabled(false);

    int randomValue = 1+ (qrand() % 6);

    if (battleHitButtonSFX->state() == QMediaPlayer::PlayingState) {
        battleHitButtonSFX->setPosition(0);
    }
    else if (battleHitButtonSFX->state() == QMediaPlayer::StoppedState) {
        battleHitButtonSFX->play();
    }

    //player hitting
    if (playerPosition.standing != true){
    playerPosition.currentTotal += randomValue;

    //demo mode on player instantly rolls crits on hit
    if (demoEngaged == true)
        playerPosition.currentTotal = 12;

    qDebug() << playerPosition.currentTotal;
    if (playerPosition.currentTotal > 12){
        if (battleBustedUserSFX->state() == QMediaPlayer::PlayingState) {
            battleBustedUserSFX->setPosition(0);
        }
        else if (battleBustedUserSFX->state() == QMediaPlayer::StoppedState) {
            battleBustedUserSFX->play();
        }

        ui->bustCritlbl->setText("You Busted");
        ui->bustCritlbl->setVisible("true");

        if(enemyIndex[engagedEnemy].currentTotal > 6 )
            playerPosition.currentTotal = 6;

        if(enemyIndex[engagedEnemy].currentTotal <= 6 && enemyIndex[engagedEnemy].currentTotal != 0)
            playerPosition.currentTotal = (enemyIndex[engagedEnemy].currentTotal - 1);


        if(enemyIndex[engagedEnemy].currentTotal == 0){
            enemyIndex[engagedEnemy].currentTotal = 1;
            playerPosition.currentTotal = 0;
        }

        playerPosition.standing = true;
        enemyIndex[engagedEnemy].standing = true;
         ui->playerStandinglbl->setVisible(true);
         ui->enemyStandinglbl->setVisible(true);
    }

    if(playerPosition.currentTotal == 12){
        playerPosition.standing = true;
        playerPosition.critical = true;
        ui->playerStandinglbl->setVisible(true);
        ui->enemyStandinglbl->setVisible(true);
    }

    ui->yourTotallbl->setText(QString::number(playerPosition.currentTotal));
}

    //enemy hitting
    if(enemyIndex[engagedEnemy].standing != true){
    repeat: // brings back to beginning if player is standing already
    randomValue = 1+(qrand() %6);
    enemyIndex[engagedEnemy].currentTotal += randomValue;

    if (enemyIndex[engagedEnemy].currentTotal > 12){
        if (battleBustedEnemySFX->state() == QMediaPlayer::PlayingState) {
            battleBustedEnemySFX->setPosition(0);
        }
        else if (battleBustedEnemySFX->state() == QMediaPlayer::StoppedState) {
            battleBustedEnemySFX->play();
        }

        ui->bustCritlbl->setText("Enemy Busted");
        ui->bustCritlbl->setVisible("true");

        if(playerPosition.currentTotal > 6 )
            enemyIndex[engagedEnemy].currentTotal = 6;

        if(playerPosition.currentTotal <= 6 && playerPosition.currentTotal != 0)
           enemyIndex[engagedEnemy].currentTotal = (playerPosition.currentTotal - 1);


        if(playerPosition.currentTotal == 0){
            playerPosition.currentTotal = 1;
            enemyIndex[engagedEnemy].currentTotal = 0;
        }

        playerPosition.standing = true;
        enemyIndex[engagedEnemy].standing = true;
        ui->playerStandinglbl->setVisible(true);
        ui->enemyStandinglbl->setVisible(true);
    }

    if(enemyIndex[engagedEnemy].currentTotal == 12){
        enemyIndex[engagedEnemy].standing = true;
        enemyIndex[engagedEnemy].critical = true;
        ui->enemyStandinglbl->setVisible(true);
    }

    if(enemyIndex[engagedEnemy].currentTotal >= 8 && enemyIndex[engagedEnemy].currentTotal <= 12){
        enemyIndex[engagedEnemy].standing = true;
        ui->enemyStandinglbl->setVisible(true);

        if(playerPosition.standing == false && !(ui->playerStandinglbl->isVisible())) {
            if (battleStandingSFX->state() == QMediaPlayer::PlayingState) {
                battleStandingSFX->setPosition(0);
            }
            else if (battleStandingSFX->state() == QMediaPlayer::StoppedState) {
                battleStandingSFX->play();
            }
        }
    }

    ui->enemyTotallbl->setText(QString::number(enemyIndex[engagedEnemy].currentTotal)); // update label

    if (playerPosition.standing == true && enemyIndex[engagedEnemy].standing == false)
        goto repeat;
  }
    if (enemyIndex[engagedEnemy].standing == true && playerPosition.standing == true)
        dealDamage();

    else {
        ui->hitButton->setEnabled(true);
        ui->standBtn->setEnabled(true);

    }

}

void GameMainWindow::on_standBtn_clicked()
{
    playerPosition.standing = true;
    ui->playerStandinglbl->setVisible(true);
    GameMainWindow::on_hitButton_clicked();
}

void GameMainWindow::on_leaderboardButton2_clicked()
{
    menuButtonSFX->play();
    overworldMusic->stop();
    menuMusic->play();
    leaderboardHandler(extraFloors);
    ui->bestScore1->setText(QString::number(highestScore));
    ui->bestScore2->setText(QString::number(secondHighestScore));
    ui->bestScore3->setText(QString::number(thirdHighestScore));
    ui->gameSWidget->setCurrentIndex(5);
    ui->menuSWidget->setCurrentIndex(0);
    ui->buttonSWidget->setCurrentIndex(0);

    enemyMovement->stop();

    ui->extraLabel->setVisible(false);
    ui->floorsClearedlbl->setVisible(false);
    extraFloors = 0;

    resetTiles();
    Floor = "one";
    floorNumber = 1;
}

void GameMainWindow::on_leaderboardButton1_clicked()
{
    menuButtonSFX->play();
    leaderboardHandler(extraFloors);
    ui->bestScore1->setText(QString::number(highestScore));
    ui->bestScore2->setText(QString::number(secondHighestScore));
    ui->bestScore3->setText(QString::number(thirdHighestScore));
    ui->gameSWidget->setCurrentIndex(5);
    ui->menuSWidget->setCurrentIndex(0);
    ui->buttonSWidget->setCurrentIndex(0);
}

void GameMainWindow::on_menuButtonFL_clicked()
{
    menuButtonSFX->play();
    ui->gameSWidget->setCurrentIndex(0);
    ui->menuSWidget->setCurrentIndex(0);
    ui->buttonSWidget->setCurrentIndex(0);
}

void GameMainWindow::leaderboardHandler(int score)
{
    int temp1 = 0;
    if(score >= highestScore)
    {
        temp1 = highestScore;
        highestScore = score;
        thirdHighestScore = secondHighestScore;
        secondHighestScore = temp1;
    }
    else if(score >= secondHighestScore)
    {
        thirdHighestScore = secondHighestScore;
        secondHighestScore = score;
    }
    else if(score >= thirdHighestScore)
    {
        thirdHighestScore = score;
    }
    endReached = false;
    ui->extraLabel->setVisible(false);
    ui->floorsClearedlbl->setVisible(false);
    extraFloors = 0;
}

void GameMainWindow::on_creditsButton1_clicked()
{
    menuButtonSFX->play();
    menuMusic->stop();
    menuCreditsMusic->play();

    ui->gameSWidget->setCurrentIndex(4);
    ui->menuSWidget->setCurrentIndex(0);
    ui->buttonSWidget->setCurrentIndex(0);
}

void GameMainWindow::on_titlButton2_clicked()
{
    overworldMusic->stop();
    //menuButtonSFX->play();
    //menuMusic->play();
    menuCreditsMusic->play();

    leaderboardHandler(extraFloors);
    ui->bestScore1->setText(QString::number(highestScore));
    ui->bestScore2->setText(QString::number(secondHighestScore));
    ui->bestScore3->setText(QString::number(thirdHighestScore));
    ui->gameSWidget->setCurrentIndex(4);
    ui->menuSWidget->setCurrentIndex(0);
    ui->buttonSWidget->setCurrentIndex(0);

    enemyMovement->stop();
    endReached = false;
    ui->extraLabel->setVisible(false);
    ui->floorsClearedlbl->setVisible(false);
    extraFloors = 0;

    resetTiles();
    Floor = "one";
    floorNumber = 1;

}

void GameMainWindow::on_menuFCButton_clicked()
{
    menuButtonSFX->play();
    menuMusic->play();
    menuCreditsMusic->stop();
    ui->gameSWidget->setCurrentIndex(0);
    ui->menuSWidget->setCurrentIndex(0);
    ui->buttonSWidget->setCurrentIndex(0);
}

void GameMainWindow::on_demoButton_clicked()
{
    //toggle demo mode off and on
    if (demoEngaged == false){
        demoEngaged = true;
        ui->demoOnlbl->setVisible(true);
    }

    else{
        demoEngaged = false;
        ui->demoOnlbl->setVisible(false);
    }
}
