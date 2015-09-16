#ifndef PLAYER_H
#define PLAYER_H
#include "desk.h"
#include <stack>
#include "skeletons.h"
#include "bonedragon.h"
class Player
{
private:
    int id;
    int playerLife;
    RealMonsterCard* hand[6];
    std::stack<RealMonsterCard*>* cardHeap;
public:
    Player(int id,int life);
    void SetLife(int value);
    void Atack(int index, Player *enemy); //攻击指令
    int LifeDec(int value); //生命值下降
    int GetLife(); //获取当前生命值
    int PutCard(RealMonsterCard *card, int deskIndex, int handIndex); //放置卡牌到战场
    int ShowHandCards(); //获取手牌信息
    int GetNextCard(); //抽牌
};

#endif // PLAYER_H
