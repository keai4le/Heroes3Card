#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    desk=Desk::GetInstance(ui);
    mr=nullptr;
    ms=nullptr;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_createGame_clicked()
{
    this->mr=new MessageReceiver(this,45454);
    this->playerId=1;
    this->enemy=2;
}

void MainWindow::on_joinGame_clicked()
{
    this->playerId=2;
    this->enemy=1;
    this->ms=new MessageReceiver(this,45455);
    int infoArr[22]={1,1,1,1,1,2,2,2,2,2,5,5,5,5,5,150,150,150,150,150,30,30};
    QByteArray infoByte;
    QDataStream in(&infoByte,QIODevice::WriteOnly);
    for(int i=0;i<22;i++)
        in << infoArr[i];
    ms->Send(infoByte,45454);
}

void MainWindow::on_m1atk_clicked()
{
    int sta = desk->Atack(playerId,0);
    if(sta!=-1)
        desk->GetPlayer(enemy)->LifeDec(sta);
    if(desk->GetPlayer(enemy)->GetLife()<0)
    {
        exit(0);
    }
}

void MainWindow::on_m2atk_clicked()
{
    int sta = desk->Atack(playerId,1);
    if(sta!=-1)
        desk->GetPlayer(enemy)->LifeDec(sta);
    if(desk->GetPlayer(enemy)->GetLife()<0)
    {
        exit(0);
    }
}

void MainWindow::on_endTurn_clicked()
{
    int* info=desk->GetDeskInfo();
    qDebug()<< "???";
    QByteArray infoByte;
    QDataStream in(&infoByte,QIODevice::WriteOnly);
    for(int i=0;i<22;i++)
        in << info[i];
    if(mr!=nullptr)
        mr->Send(infoByte,45455);
    else
        ms->Send(infoByte,45454);
    //qDebug() << s << senderAddr << senderPort;
}
