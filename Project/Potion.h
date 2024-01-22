//
// Created by Sarah-El Feel on 29/10/2023.
//

#ifndef PROJECT_POTION_H
#define PROJECT_POTION_H
#include "Item.h"

class Potion : public Item{
    int noHeal;

public:
    Potion();
    ~Potion();
    Potion(char type, int noHeal);

    int getNoHeal() const;

    void setNoHeal(int noHeal);
};

#endif //PROJECT_POTION_H
