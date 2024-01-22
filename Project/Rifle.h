//
// Created by Sarah-El Feel on 29/10/2023.
//

#ifndef PROJECT_RIFLE_H
#define PROJECT_RIFLE_H


#include "Object.h"
#include "Character.h"
#include "Hero.h"

class Rifle: public Gun{


public:
    Rifle();
    ~Rifle();
    Rifle(char type, const string &name);
    void useSpecial(Hero& h1 , Object* map[15][15]);
};


#endif //PROJECT_RIFLE_H
