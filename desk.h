#ifndef DESK_H
#define DESK_H
#include <iostream>
#include <iomanip>
#include "realmonstercard.h"
#include "skeletons.h"
#include "bonedragon.h"
#include "player.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "nomonster.h"
class Player;
class Desk
{
private:
    static Desk* desk;
    int* deskInfo;
    Desk();
    Desk(Ui_MainWindow *m);
    RealMonsterCard* player1Cards[5];
    RealMonsterCard* player2Cards[5];
    Player *p1;
    Player *p2;
    Ui_MainWindow *m;
public:
    Player* GetPlayer(int id);
    void setP1(Player *p1);
    void setP2(Player *p2);
    void SetDeskFromInfo(int deskInfo[22]);
    int *GetDeskInfo();
    static Desk* GetInstance(Ui_MainWindow *m=0);
    int PutCard(int playerId,int index,RealMonsterCard* card);
    int Atack(int playerId,int index);
    RealMonsterCard* GetMonster(int player,int index);
    void AtackBetween2Monster(int player,int index);
    void PrintDesk();
    void PrintDot(int count);
    void PrintElement(RealMonsterCard** playerCards);
};

#endif // DESK_H
