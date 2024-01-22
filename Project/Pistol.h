//
// Created by Sarah-El Feel on 29/10/2023.
//

#ifndef PROJECT_PISTOL_H
#define PROJECT_PISTOL_H

#include "Object.h"
#include "Character.h"
#include "Hero.h"

class Pistol: public Gun{


public:
    Pistol();
    ~Pistol();
    Pistol(char type, const string &name);
    void useSpecial(Hero& h1 , Object* map[15][15]);
};

#endif //PROJECT_PISTOL_H
