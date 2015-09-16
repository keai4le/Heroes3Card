#include "monster.h"


int Monster::GetAtk() const
{
    return this->atk;
}

int Monster::GetDef() const
{
    return this->def;
}
Monster::Monster(char *name, int life, int atk, int def, int dmg)
{
    this->name=name;
    this->life=life;
    this->atk=atk;
    this->def=def;
    this->dmg=dmg;
}
int Monster::GetLife() const
{
    return this->life;
}

char *Monster::GetName() const
{
    return this->name;
}

