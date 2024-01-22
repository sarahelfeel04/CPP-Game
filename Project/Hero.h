//
// Created by Sarah-El Feel on 29/10/2023.
//

#ifndef PROJECT_HERO_H
#define PROJECT_HERO_H
#include "Object.h"
#include "Character.h"
#include "Gun.h"
#include "Ammo.h"
#include "Potion.h"
#include "Monster.h"


class Hero: public Character {
private:
    Gun* gun;

public:
    //Hero(char type, const Point &p, int hP, const Gun *gun);
    Hero();
    virtual ~Hero();
    Hero(char type, int x, int y, int hP, Gun *gun) ;

public:
    //const Gun &getGun() const;

    //void setGun(const Gun &gun);
    Gun *getGun() const;

    void setGun(Gun *gun);


    Hero& operator+(const Ammo& a);
    Hero& operator+(const Potion& p);
    Hero& operator-( Monster& m);
    friend ostream& operator<<(ostream& os,  Hero& hero);

    virtual void useSpecial();

};


#endif //PROJECT_HERO_H
