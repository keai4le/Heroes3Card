#include "desk.h"
Desk* Desk::desk=nullptr;
Desk::Desk()
{
    for(int i=0;i<5;i++)
    {
        this->player1Cards[i]=nullptr;
        this->player2Cards[i]=nullptr;
    }
    this->deskInfo=new int[22];
}

Desk::Desk(Ui_MainWindow *m)
{
    this->m=m;
    for(int i=0;i<5;i++)
    {
        this->player1Cards[i]=nullptr;
        this->player2Cards[i]=nullptr;
    }
    this->deskInfo=new int[22];
}

Player *Desk::GetPlayer(int id)
{
    if(id==1)
        return this->p1;
    else return this->p2;
}

void Desk::setP1(Player *p1)
{
    this->p1=p1;
}
void Desk::setP2(Player *p2)
{
    this->p2=p2;
}

void Desk::SetDeskFromInfo(int deskInfo[22])
{
    //设置玩家1的战场信息
    for(int i=0;i<5;i++)
    {
        switch (deskInfo[i]) {
        case 1:
            player1Cards[i]=new RealMonsterCard(Skeletons::GetInstance(),1);
            player1Cards[i]->SetLife(deskInfo[i+10]);
            break;
        case 2:
            player1Cards[i]=new RealMonsterCard(BoneDragon::GetInstance(),2);
            player1Cards[i]->SetLife(deskInfo[i+10]);
            break;
        case 3:
            player1Cards[i]=new RealMonsterCard(NoMonster::GetInstance(),3);
            player1Cards[i]->SetLife(0);
            break;
        default:
            player1Cards[i]=nullptr;
            break;
        }
    }
    //设置玩家2的战场信息
    for(int i=5;i<10;i++)
    {
        switch (deskInfo[i]) {
        case 1:
            player2Cards[i-5]=new RealMonsterCard(Skeletons::GetInstance(),1);
            player2Cards[i-5]->SetLife(deskInfo[i+10]);
            break;
        case 2:
            player2Cards[i-5]=new RealMonsterCard(BoneDragon::GetInstance(),2);
            player2Cards[i-5]->SetLife(deskInfo[i+10]);
            break;
        case 3:
            player2Cards[i-5]=new RealMonsterCard(NoMonster::GetInstance(),3);
            player2Cards[i-5]->SetLife(0);
            break;
        default:
            player2Cards[i-5]=nullptr;
            break;
        }
    }
    Desk::GetInstance()->GetPlayer(1)->SetLife(deskInfo[20]);
    Desk::GetInstance()->GetPlayer(2)->SetLife(deskInfo[21]);
}
//收集战场信息准备传输
int* Desk::GetDeskInfo()
{
    for(int i=0;i<5;i++)
    {
        deskInfo[i]=player1Cards[i]->GetTypeNo();
        deskInfo[i+10]=player1Cards[i]->GetLife();
    }
    //std::cout <<"123";
    for(int i=5;i<10;i++)
    {
        deskInfo[i]=player2Cards[i-5]->GetTypeNo();
        deskInfo[i+10]=player2Cards[i-5]->GetLife();
    }
    this->deskInfo[20]=Desk::GetInstance()->GetPlayer(1)->GetLife();
    this->deskInfo[21]=Desk::GetInstance()->GetPlayer(2)->GetLife();
    //std::cout <<"123";
    return deskInfo;
}

Desk* Desk::GetInstance(Ui_MainWindow *m)
{
    if(Desk::desk==nullptr)
        Desk::desk=new Desk(m);
    return Desk::desk;
}



RealMonsterCard* Desk::GetMonster(int player, int index)
{
    switch (player) {
    case 1:
        return player1Cards[index];
    case 2:
        return player2Cards[index];
    }
    return nullptr;
}



int Desk::PutCard(int playerId, int index,RealMonsterCard* card)
{
    if(playerId==1 && player1Cards[index]==nullptr)
    {
        player1Cards[index]=card;
        return 0;
    }
    if(playerId==2 && player2Cards[index]==nullptr)
    {
        player2Cards[index]=card;
        return 0;
    }
    return -1;
}


void Desk::PrintDesk()
{
//    std::cout << std::endl;
//    std::cout << "Player 1:Current Life:" << this->p1->GetLife()<< std::endl;
//    std::cout << std::endl;
//    PrintDot(50);
//    PrintElement(player1Cards);
//    PrintDot(50);
//    PrintDot(50);
//    PrintElement(player2Cards);
//    PrintDot(50);
//    std::cout << std::endl;
//    std::cout << "Player 2:Current Life:" << this->p2->GetLife() << std::endl;
//    std::cout << std::endl;
    m->m0->setText(player1Cards[0]->GetName());
    m->m1->setText(player1Cards[1]->GetName());
    m->m2->setText(player1Cards[2]->GetName());
    m->m3->setText(player1Cards[3]->GetName());
    m->m4->setText(player1Cards[4]->GetName());
    m->m5->setText(player2Cards[0]->GetName());
    m->m6->setText(player2Cards[1]->GetName());
    m->m7->setText(player2Cards[2]->GetName());
    m->m8->setText(player2Cards[3]->GetName());
    m->m9->setText(player2Cards[4]->GetName());
    m->enemyLife->setText(QString::number(p1->GetLife()));
    m->life->setText(QString::number(p2->GetLife()));
}

void Desk::PrintDot(int count)
{
    for(int i=0;i<count;i++)
        std::cout << ".";
    std::cout <<std::endl;
}

void Desk::PrintElement(RealMonsterCard** playerCards)
{
    char* dot="..........";
    for(int i=0;i<5;i++)
        if(playerCards[i]!=nullptr)
            std::cout << ".LIFE:" << std::setw(3) << playerCards[i]->GetLife() << '.';
        else
            std::cout << dot;
    std::cout << std::endl;
    for(int i=0;i<5;i++)
        if(playerCards[i]!=nullptr)
            std::cout << ".ATK :" << std::setw(3) << playerCards[i]->GetAtk() << '.';
        else
            std::cout << dot;
    std::cout << std::endl;
    for(int i=0;i<5;i++)
        if(playerCards[i]!=nullptr)
            std::cout << ".DEF :" << std::setw(3) << playerCards[i]->GetDef() << '.';
        else
            std::cout << dot;
    std::cout << std::endl;
}


int Desk::Atack(int playerId, int index)
{
    //std::cout << "atacking" <<std::endl;
    RealMonsterCard* p1=player1Cards[index];
    RealMonsterCard* p2=player2Cards[index];
    if(p1->GetTypeNo()!=3 && p2->GetTypeNo()!=3)
    {
        this->AtackBetween2Monster(playerId,index);
        return 0;
    }
    switch (playerId) {
    case 1:
        if(p1->GetTypeNo()==3)
            return -1;
        else
            return p1->GetAtk();
        break;
    case 2:
        if(p2->GetTypeNo()==3)
            return -1;
        else
            return p2->GetAtk();
    default:
        break;
    }
    return -1;
}

void Desk::AtackBetween2Monster(int player,int index)
{
    RealMonsterCard* p1=player1Cards[index];
    RealMonsterCard* p2=player2Cards[index];
    switch (player) {
    case 1:
        p2->LifeDec(p1->GetAtk());
        if(p2->GetLife()<0)
        {
            player2Cards[index]=new RealMonsterCard(NoMonster::GetInstance(),3);
            break;
        }
        p1->LifeDec(p2->GetAtk());
        if(p1->GetLife()<0)
            player1Cards[index]=new RealMonsterCard(NoMonster::GetInstance(),3);
        break;
    case 2:
        p1->LifeDec(p2->GetAtk());
        if(p1->GetLife()<0)
        {
            p1=new RealMonsterCard(NoMonster::GetInstance(),3);
            break;
        }
        p2->LifeDec(p1->GetAtk());
        if(p2->GetLife()<0)
            p2=new RealMonsterCard(NoMonster::GetInstance(),3);
        break;
    default:
        break;
    }
}
