#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "messagesender.h"
#include "messagereceiver.h"
#include <QDataStream>
#include "desk.h"
#include <QUdpSocket>
class MessageReceiver;
class MessageSender;
class Desk;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_createGame_clicked();

    void on_joinGame_clicked();

    void on_m1atk_clicked();

    void on_m2atk_clicked();

    void on_endTurn_clicked();

private:
    Ui::MainWindow *ui;
    MessageReceiver *mr;
    MessageReceiver *ms;
    Desk *desk;
    int playerId;
    int enemy;
    quint16 port;
};

#endif // MAINWINDOW_H
