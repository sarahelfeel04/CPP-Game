//
// Created by Sarah-El Feel on 29/10/2023.
//

#ifndef PROJECT_BAZOOKA_H
#define PROJECT_BAZOOKA_H

#include "Object.h"
#include "Character.h"
#include "Hero.h"

class Bazooka: public Gun{


public:
    Bazooka();
    ~Bazooka();
    Bazooka(char type, const string &name);
    void useSpecial(Hero& h1 , Object* map[15][15]);
};

#endif
