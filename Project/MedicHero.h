//
// Created by Sarah-El Feel on 29/10/2023.
//

#ifndef PROJECT_MEDICHERO_H
#define PROJECT_MEDICHERO_H

#include "Object.h"
#include "Character.h"
#include "Gun.h"

class MedicHero: public Hero{
private:
    int heal;

public:
    MedicHero(char type, int x , int y, int hP,  Gun *gun, int heal) ;
    MedicHero();
    ~MedicHero();

    int getHeal() const;
    void setHeal(int heal);
    void useSpecial();
};



#endif //PROJECT_MEDICHERO_H
