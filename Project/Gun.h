//
// Created by Sarah-El Feel on 29/10/2023.
//

#ifndef PROJECT_GUN_H
#define PROJECT_GUN_H
#include <cstring>
#include "Object.h"
#include "Character.h"
//#include "Hero.h"

class Hero;
class Gun:public Object{
private:
    string name;
    int noBullet;
    int dmg;
    int range;

public:
    Gun(char type, const string &name, int noBullet, int dmg, int range);
    Gun();
    virtual ~Gun();


    const string &getName() const;

    void setName(const string &name);

    int getNoBullet() const;

    void setNoBullet(int noBullet);

    int getDmg() const;

    void setDmg(int dmg);

    int getRange() const;

    void setRange(int range);
    virtual void useSpecial(Hero& h1 , Object* map[15][15]);
    friend ostream& operator<<(ostream& os,  Gun& gun);

};

#endif //PROJECT_GUN_H
