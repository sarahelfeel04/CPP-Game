//
// Created by Sarah-El Feel on 29/10/2023.
//

#ifndef PROJECT_DEMOLITIONHERO_H
#define PROJECT_DEMOLITIONHERO_H

#include "Object.h"
#include "Character.h"
#include "Gun.h"

class DemolitionHero: public Hero{

private:
    Gun* extra;
    bool has_Two;

public:
    DemolitionHero(char type, int x , int y, int hP,  Gun *gun,  Gun *extra) ;
    DemolitionHero();
    DemolitionHero(char type, int x , int y, int hP,  Gun *gun) ;
    ~DemolitionHero();


    Gun *getExtra() const;

    void setExtra(Gun *extra);

    bool hasTwo() const;
    void setHasTwo(bool hasTwo);
    //DemolitionHero& operator+(const Ammo& a);
    void useSpecial();

};


#endif //PROJECT_DEMOLITIONHERO_H
