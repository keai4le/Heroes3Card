#include "nomonster.h"
NoMonster* NoMonster::noMonster=nullptr;
NoMonster::NoMonster():Monster("NoMonster",0,0,0,0)
{

}

NoMonster *NoMonster::GetInstance()
{
    if(noMonster==nullptr)
        noMonster=new NoMonster();
    return noMonster;
}

