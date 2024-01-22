//
// Created by Sarah-El Feel on 29/10/2023.
//

#ifndef PROJECT_AMMO_H
#define PROJECT_AMMO_H
#include "Item.h"

class Ammo : public Item{
    int bullCollected;

public:
    Ammo();
    ~Ammo();
    Ammo(char type, int bullCollected) ;

    int getBullCollected() const;
    void setBullCollected(int bullCollected);
};

#endif //PROJECT_AMMO_H
