//
// Created by Sarah-El Feel on 29/10/2023.
//

#ifndef PROJECT_OBJECT_H
#define PROJECT_OBJECT_H

class Object{
private:
    char type;

public:
    Object();
    Object(char type);
    virtual ~Object();
    char getType() const;
    void setType(char type);
    friend ostream& operator<<(ostream& os, const Object& hero);


};
#endif //PROJECT_OBJECT_H
