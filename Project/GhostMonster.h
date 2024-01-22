//
// Created by Sarah-El Feel on 29/10/2023.
//

#ifndef PROJECT_GHOSTMONSTER_H
#define PROJECT_GHOSTMONSTER_H
#include "Character.h"
#include "Monster.h"
#include <cstring>

class GhostMonster: public Monster{
private:
    bool is_Visble;
public:
    static bool status;
    GhostMonster(char type, int x , int y, int hP, const string &name, bool isVisble) ;
    GhostMonster();
    ~GhostMonster();

    bool isVisble() const;
    void setIsVisble(bool isVisble);

};


#endif //PROJECT_GHOSTMONSTER_H
