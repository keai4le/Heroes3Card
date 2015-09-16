#ifndef NOMONSTER_H
#define NOMONSTER_H
#include "monster.h"

class NoMonster : public Monster
{
private:
    static NoMonster *noMonster;
    NoMonster();
public:
    static NoMonster* GetInstance();
};

#endif // NOMONSTER_H
