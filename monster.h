#ifndef MONSTER_H
#define MONSTER_H
#include "card.h"

class Monster : public Card
{
protected:
    char* name;
    int life;
    int atk;
    int def;
    int dmg;
public:
    Monster(char* name,int life,int atk,int def,int dmg);
    int GetLife() const;
    char* GetName()const;
    int GetAtk() const;
    int GetDef() const;
};

#endif // MONSTER_H
