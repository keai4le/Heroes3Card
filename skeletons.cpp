#include "skeletons.h"
Skeletons* Skeletons::skeletons=nullptr;
Skeletons::Skeletons():Monster("Skeleton",10,5,4,5)
{

}

Skeletons *Skeletons::GetInstance()
{
    if (skeletons==nullptr)
        skeletons=new Skeletons();
    return skeletons;
}

