//
// Created by Sarah-El Feel on 29/10/2023.
//

#ifndef PROJECT_TANKMONSTER_H
#define PROJECT_TANKMONSTER_H
#include "Character.h"
#include "Monster.h"
#include <cstring>

class TankMonster: public Monster{
private:
    int shield;
public:
    TankMonster(char type,int x , int y, int hP, const string &name, int shield) ;
    TankMonster();
    ~TankMonster();



    int getShield() const;
    void setShield(int shield);

    void reduceHp(int dmg);
};

#endif //PROJECT_TANKMONSTER_H
