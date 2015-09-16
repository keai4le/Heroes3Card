#ifndef MESSAGERECEIVER_H
#define MESSAGERECEIVER_H
#include <QDebug>
#include <QObject>
#include <QUdpSocket>
#include <QDataStream>
#include "desk.h"
#include "mainwindow.h"

class MessageReceiver : public QObject
{
    Q_OBJECT
private:
    QUdpSocket *udpSocket;
    QHostAddress senderAddr;
    quint16 senderPort;
public:
    explicit MessageReceiver(QObject *parent = 0,quint16 port=0);
    void Send(QByteArray &byteArr,quint16 portToSend);

signals:

public slots:
    void processPendingDatagrams();
};

#endif // MESSAGERECEIVER_H
