#include "messagereceiver.h"

MessageReceiver::MessageReceiver(QObject *parent, quint16 port) : QObject(parent)
{
    this->senderPort=port;
    udpSocket=new QUdpSocket(this);
    udpSocket->bind(QHostAddress::LocalHost,port);
    connect(udpSocket,SIGNAL(readyRead()),
            this,SLOT(processPendingDatagrams()));
    Desk::GetInstance()->setP1(new Player(1,20));
    Desk::GetInstance()->setP2(new Player(2,20));
}

void MessageReceiver::Send(QByteArray &byteArr, quint16 portToSend)
{
    udpSocket->writeDatagram(byteArr,QHostAddress::LocalHost,portToSend);
}

void MessageReceiver::processPendingDatagrams()
{
    while(udpSocket->hasPendingDatagrams())
    {
        QByteArray datagram;
        datagram.resize(udpSocket->pendingDatagramSize());
        udpSocket->readDatagram(datagram.data(),datagram.size(),&senderAddr,&senderPort);
        QDataStream out(&datagram,QIODevice::ReadOnly);
        int deskInfo[22];
        for(int i=0;i<22;i++)
        {
            out >> deskInfo[i];
            qDebug() << deskInfo[i];
        }

        Desk *desk=Desk::GetInstance();

        desk->SetDeskFromInfo(deskInfo);
        desk->PrintDesk();
        //qDebug() << "info";
        //std::cout << "please input an pos to atack(1--5)" << std::endl;
        //int i;
        //std::cin >> i;
//        int sta=desk->Atack(1,i-1);
//        if(sta!=-1)
//            desk->GetPlayer(2)->LifeDec(sta);
//        if(desk->GetPlayer(2)->GetLife()<0)
//        {
//            std::cout <<"Game Over!" << std::endl;
//            exit(0);
//        }
        //qDebug()<< "???";
//        int* info=desk->GetDeskInfo();
        //qDebug()<< "???";
//        QByteArray infoByte;
//        QDataStream in(&infoByte,QIODevice::WriteOnly);
//        for(int i=0;i<22;i++)
//            in << info[i];
//        int s=udpSocket->writeDatagram(infoByte,this->senderAddr,this->senderPort);
//        qDebug() << s << senderAddr << senderPort;

    }
}

