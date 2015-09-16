#include "bonedragon.h"
BoneDragon* BoneDragon::boneDragon=nullptr;
BoneDragon::BoneDragon():Monster("BoneDragon",150,20,15,25)
{

}
BoneDragon* BoneDragon::GetInstance()
{
    if(boneDragon==nullptr)
        boneDragon=new BoneDragon();
    return boneDragon;
}

