#ifndef REALMONSTERCARD_H
#define REALMONSTERCARD_H
#include "monster.h"

class RealMonsterCard
{
private:
    Monster* monsterType;
    int life;
    int typeNo;
public:
    RealMonsterCard(Monster *type,int typeNo);
    int LifeDec(int damage);
    void SetLife(int value);
    int GetTypeNo();
    char* GetName();
    int GetAtk();
    int GetLife();
    int GetDef();
};

#endif // REALMONSTERCARD_H
