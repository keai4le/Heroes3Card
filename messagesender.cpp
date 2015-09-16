#include "messagesender.h"

MessageSender::MessageSender(QObject *parent) : QObject(parent)
{
    udpSocket=new QUdpSocket(this);
    udpSocket->bind(QHostAddress::LocalHost,45455);
    //localPort = udpSocket->localPort();
    //qDebug() << localPort;
    connect(udpSocket,SIGNAL(readyRead()),
            this,SLOT(processPendingDatagrams()));
    Desk::GetInstance()->setP1(new Player(1,20));
    Desk::GetInstance()->setP2(new Player(2,20));
}

void MessageSender::Send(QByteArray &byteArr)

{
    udpSocket->writeDatagram(byteArr,QHostAddress::LocalHost,45454);
}

void MessageSender::processPendingDatagrams()
{
    while(udpSocket->hasPendingDatagrams())
    {
        QByteArray datagram;
        datagram.resize(udpSocket->pendingDatagramSize());
        udpSocket->readDatagram(datagram.data(),datagram.size());
        QDataStream out(&datagram,QIODevice::ReadOnly);
        int deskInfo[22];
        for(int i=0;i<22;i++)
            out >> deskInfo[i];
        Desk *desk=Desk::GetInstance();
        desk->SetDeskFromInfo(deskInfo);
        desk->PrintDesk();
//        std::cout << "please input an pos to atack(1--5)" << std::endl;
//        int i;
//        std::cin >> i;
//        int sta=desk->Atack(2,i-1);
//        if(sta!=-1)
//            desk->GetPlayer(1)->LifeDec(sta);
//        if(desk->GetPlayer(1)->GetLife()<0)
//        {
//            std::cout <<"Game Over!" << std::endl;
//            exit(0);
//        }
        //qDebug()<< "???";
        int* info=desk->GetDeskInfo();
        //qDebug()<< "???";
        QByteArray infoByte;
        QDataStream in(&infoByte,QIODevice::WriteOnly);
        for(int i=0;i<22;i++)
            in << info[i];
        udpSocket->writeDatagram(infoByte,QHostAddress::LocalHost,45454);
        //qDebug() << senderAddr << senderPort;

    }
}
