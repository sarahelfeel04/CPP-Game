//
// Created by Sarah-El Feel on 29/10/2023.
//

#ifndef PROJECT_MONSTER_H
#define PROJECT_MONSTER_H
#include "Character.h"
#include <cstring>

class Monster : public Character{
private:
    string name;
public:
    Monster(char type, int x , int y, int hP, const string &name);
    Monster();
    virtual ~Monster();

    const string &getName() const;
    void setName(const string &name);


};
#endif //PROJECT_MONSTER_H
