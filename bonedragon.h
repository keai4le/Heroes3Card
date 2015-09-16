#ifndef BONEDRAGON_H
#define BONEDRAGON_H
#include "monster.h"

class BoneDragon : public Monster
{
private:
    static BoneDragon* boneDragon;
    BoneDragon();
public:
    static BoneDragon* GetInstance();
};

#endif // BONEDRAGON_H
