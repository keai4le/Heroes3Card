#include <QCoreApplication>
#include <QApplication>
#include <iostream>
#include "realmonstercard.h"
#include "monster.h"
#include "skeletons.h"
#include "bonedragon.h"
#include "desk.h"
#include "player.h"
#include <QUdpSocket>
#include "messagereceiver.h"
#include "messagesender.h"
#include <QDataStream>
#include "mainwindow.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    std::cout << "Heroes3------Shadow Of Death" <<std::endl;
//    //生成骷髅和骨龙
//    Monster* skeletons=Skeletons::GetInstance();
//    Monster* bonedragon=BoneDragon::GetInstance();
//    //产生骷髅和骨龙的两张卡牌
//    RealMonsterCard* c1=new RealMonsterCard(skeletons);
//    RealMonsterCard* c2=new RealMonsterCard(bonedragon);
//    //生成两位玩家
//    Player* p1=new Player(1,20);
//    Player* p2=new Player(2,20);
//    //获得战斗场,并打印战场
//    Desk* desk=Desk::GetInstance();
//    //设置玩家
//    desk->setP1(p1);
//    desk->setP2(p2);
//    p1->ShowHandCards();
//    desk->PrintDesk();
//    //玩家1，2分别将卡放入各自场地的0位置
//    desk->PutCard(1,0,c1);
//    desk->PutCard(2,0,c2);
//    //玩家1发动攻击
//    desk->PrintDesk();
//    p1->Atack(0,p2);
//    p2->Atack(0,p1);
//    desk->PrintDesk();
    MainWindow m;
    m.show();
//    MessageReceiver *mr;
//    MessageSender *ms;
//    QByteArray message;
//    QByteArray lifeByte;
//    QByteArray typeByte;
//    int infoArr[22]={1,1,1,1,1,2,2,2,2,2,5,5,5,5,5,150,150,150,150,150,30,30};
//    QDataStream in(&lifeByte,QIODevice::WriteOnly);
//    for(int i=0;i<11;i++)
//        std::cout << lifeArr[i];
//    char choose; //
//    std::cout <<"Do you want to CREATE a game or JOIN in a game,input C/J"<<std::endl;
//    std::cin >> choose;
//    while(choose!='C' && choose!='J')
//    {
//        std::cout << "PLEASE INPUT C OR J" <<std::endl;
//        std::cin >> choose;
//    }
//    switch (choose) {
//    case 'C':
//        mr=new MessageReceiver();
//        break;
//    case 'J':
//        ms=new MessageSender();
//        for(int i=0;i<22;i++)
//            in << infoArr[i];
//        ms->Send(lifeByte);
//    default:
//        break;
//    }

    return a.exec();
}
