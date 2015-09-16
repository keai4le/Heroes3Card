#include "realmonstercard.h"

RealMonsterCard::RealMonsterCard(Monster* type, int typeNo)
{
    this->monsterType=type;
    this->life=type->GetLife();
    this->typeNo=typeNo;
}
int RealMonsterCard::LifeDec(int damage)
{
    this->life-=damage;
    return this->life;
}

void RealMonsterCard::SetLife(int value)
{
    this->life=value;
}

int RealMonsterCard::GetTypeNo()
{
    return this->typeNo;
}

char *RealMonsterCard::GetName()
{
    return this->monsterType->GetName();
}

int RealMonsterCard::GetAtk()
{
    return monsterType->GetAtk();
}

int RealMonsterCard::GetLife()
{
    return this->life;
}

int RealMonsterCard::GetDef()
{
    return monsterType->GetDef();
}
