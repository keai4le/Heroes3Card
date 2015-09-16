#include "player.h"

Player::Player(int id, int life)
{
    this->id=id;
    this->playerLife=life;
    this->cardHeap=new std::stack<RealMonsterCard*>();
    for(int i=0;i<6;i++)
    {
        this->cardHeap->push(new RealMonsterCard(Skeletons::GetInstance(),1));
    }
    for(int i=0;i<6;i++)
    {
        if(!this->cardHeap->empty())
        {
            this->hand[i]=this->cardHeap->top();
            this->cardHeap->pop();
        }
        else
            break;
    }
}

void Player::SetLife(int value)
{
    this->playerLife=value;
}

void Player::Atack(int index,Player* enemy)
{
    int stat = Desk::GetInstance()->Atack(this->id,index);
    if(stat>0)
        enemy->LifeDec(stat);
    if(stat==-1)
        std::cout << "atack failed,you may don't have monster at this position" << std::endl;
}

int Player::LifeDec(int value=0)
{
    this->playerLife-=value;
    std::cout << "Player:" <<this->id << "'s Life -" << value << " ,Current Life Value Is : " << this->playerLife << std::endl;
    if(this->playerLife<=0)
    {
        std::cout << "GAME OVER " << "Player " << this->id << " failed" << std::endl;
        exit(0);
    }
    return this->playerLife;
}

int Player::GetLife()
{
    return this->playerLife;
}

int Player::PutCard(RealMonsterCard* card,int deskIndex,int handIndex)
{
    int stat=Desk::GetInstance()->PutCard(this->id,deskIndex,card);
    if(stat==0)
    {
        delete hand[handIndex];
        this->hand[handIndex]=nullptr;
        return 0;
    }
    return -1;
}

int Player::ShowHandCards()
{
    std::cout << "Player " << this->id << "'s hand cards:" << std::endl;
    for(int i=0;i<6;i++)
        if(this->hand[i]!=nullptr)
            std::cout << hand[i]->GetName() << " ->index:"<< i << std::endl;
    return 0;
}

int Player::GetNextCard()
{
    int i=0;
    while(i<6 && !this->cardHeap->empty())
    {
        if(this->hand[i]==nullptr)
        {
            this->hand[i]=this->cardHeap->top();
            this->cardHeap->pop();
            return 0;
        }
        i++;
    }
    if(i==6)
    {
        std::cout << "No more Empty position in your hand" << std::endl;
        return -1;
    }
    std::cout << "No more Card On the Heap!" << std::endl;
    return -2;
}



