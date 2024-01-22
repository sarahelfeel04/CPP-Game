//
// Created by Sarah-El Feel on 29/10/2023.
//

#ifndef PROJECT_CHARACTER_H
#define PROJECT_CHARACTER_H
#include "Object.h"


class Character : public Object {
private:
    int x;
    int y;

    int hP;
public:
    //Character(char type, const Point p, int hP); //: Object(type), x(x), y(y), hP(hP)
    Character();
    virtual ~Character();

    Character(char type, int x, int y, int hP);

    int getX() const;

    void setX(int x);

    int getY() const;

    void setY(int y);

    int getHp() const ;
    void setHp(int hP) ;




};



#endif //PROJECT_CHARACTER_H
