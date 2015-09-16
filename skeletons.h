#ifndef SKELETONS_H
#define SKELETONS_H
#include "monster.h"

class Skeletons : public Monster
{
private:
    static Skeletons* skeletons;
    Skeletons();
public:
    static Skeletons* GetInstance();
};

#endif // SKELETONS_H
