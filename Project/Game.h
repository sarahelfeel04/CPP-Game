//
// Created by Sarah-El Feel on 29/10/2023.
//

#ifndef PROJECT_GAME_H
#define PROJECT_GAME_H
#include "Hero.h"
#include "Object.h"

class Game{
public:
    Object *grid[15][15];
private:

    //static const int rows=15;
    //static const int cols=15;

    int rows=15;
    int cols=15;
    Hero* currHero;
public:
    static int round;
    static int oldRound;
public:
    ~Game();
    Game();
    //Game(Object ***grid,  Hero *currHero);

    void GenerateMap();
    void showMap();
    void startGame();
    Object *(*getGrid())[15] ;

    void setGrid(Object* grid[15][15]);

    int getRows() const;
    void setRows(int rows);
    int getCols() const;
    void setCols(int cols);
    Hero *getCurrHero() const;
    void setCurrHero(Hero *currHero);
    void move(Hero& h1 , char direction);
    void FireGun(char direction);
    void useGunSpecial() ;
    int checkGameOver();
    bool foundMonster();
    void updateMap();

};





#endif //PROJECT_GAME_H
