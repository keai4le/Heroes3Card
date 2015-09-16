#ifndef MESSAGESENDER_H
#define MESSAGESENDER_H
#include <iostream>
#include <QObject>
#include <QUdpSocket>
#include <QDataStream>
#include "desk.h"
#include <QDebug>
class MessageSender : public QObject
{
    Q_OBJECT
private:
    QUdpSocket *udpSocket;
    quint16 localPort;
public:
    explicit MessageSender(QObject *parent = 0);
    void Send(QByteArray &byteArr);

signals:

public slots:
    void processPendingDatagrams();
};

#endif // MESSAGESENDER_H
