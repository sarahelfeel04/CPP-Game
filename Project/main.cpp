#include <iostream>
using namespace std;
#include "Object.h"
#include "Hero.h"
#include "Ammo.h"
#include "Bazooka.h"
#include "Character.h"
#include "DemolitionHero.h"
#include "Game.h"
#include "GhostMonster.h"
#include "Item.h"
#include "MedicHero.h"
#include "Monster.h"
#include "Pistol.h"
#include "Potion.h"
#include "Rifle.h"
#include "TankMonster.h"
#include "Gun.h"
#include <cstdlib>
#include <stdlib.h>
#include <ctime>

//Object class

Object:: Object(){}
Object::Object(char type): type(type){}
Object::~Object(){}
char Object:: getType() const{
    return type;
}
void Object:: setType(char type){
    this->type =type;
}


//Character Class


Character :: Character (){}
Character::~Character(){}



int Character::getHp() const {
    return hP;
}
void Character::setHp(int hP) {
    if (hP>0)
        this->hP=hP;
    else
        this->hP=0;
}

Character::Character(char type, int x, int y, int hP) : Object(type), x(x), y(y), hP(hP) {}

int Character::getX() const {
    return x;
}

void Character::setX(int x) {
    Character::x = x;
}

int Character::getY() const {
    return y;
}

void Character::setY(int y) {
    Character::y = y;
}


//Hero class

Hero::Hero(char type, int x, int y, int hP, Gun *gun) : Character(type, x, y, hP), gun(gun){}
Hero::Hero(){}
Hero::~Hero(){
    delete gun;
}

Gun *Hero::getGun() const {
    return gun;
}
void Hero::setGun(Gun *gun) {
    this->gun = gun;
}


//MedicHero class

MedicHero:: MedicHero(char type, int x, int y, int hP,  Gun *gun, int heal) : Hero(type, x, y, hP, gun), heal(heal) {}
MedicHero:: MedicHero(){}
MedicHero:: ~MedicHero(){}
int MedicHero::getHeal() const {
    return heal;
}
void MedicHero::setHeal(int heal) {
    this->heal = heal;
}

//DemolitionHero

DemolitionHero::DemolitionHero(char type, int x, int y, int hP,  Gun *gun,  Gun *extra) : Hero(type, x, y, hP,gun),extra(extra), has_Two(true) {}
DemolitionHero::DemolitionHero(char type, int x, int y, int hP,  Gun *gun) : Hero(type, x, y, hP, gun), has_Two(false)  {}
DemolitionHero::DemolitionHero(){}
DemolitionHero::~DemolitionHero(){
    delete extra;
}

bool DemolitionHero::hasTwo() const {
    return has_Two;
}
void DemolitionHero::setHasTwo(bool hasTwo) {
    this->has_Two = hasTwo;
}
Gun *DemolitionHero::getExtra() const {
    return extra;
}
void DemolitionHero::setExtra(Gun *extra) {
    this->extra = extra;
}

//Gun class

Gun::Gun(char type, const string &name, int noBullet, int dmg, int range) : Object(type), name(name), noBullet(noBullet),dmg(dmg), range(range) {}
Gun:: Gun (){}
Gun:: ~Gun(){}

const string &Gun::getName() const {
    return name;
}
void Gun::setName(const string &name) {
    this->name = name;
}
int Gun::getNoBullet() const {
    return noBullet;
}
void Gun::setNoBullet(int noBullet) {
    this->noBullet = noBullet;
}
int Gun::getDmg() const {
    return dmg;
}
void Gun::setDmg(int dmg) {
    this->dmg = dmg;
}
int Gun::getRange() const {
    return range;
}
void Gun::setRange(int range) {
    this->range = range;
}


//Pistol Class

Pistol:: Pistol(char type, const string &name) : Gun(type, name, 16, 30, 2) {}
Pistol::Pistol(){}
Pistol::~Pistol(){}

//Bazooka Class

Bazooka:: Bazooka(char type, const string &name) : Gun(type, name, 4, 150, 8) {}
Bazooka::Bazooka(){}
Bazooka::~Bazooka(){}

//Rifle Class

Rifle:: Rifle(char type, const string &name) : Gun(type, name, 30, 20, 4) {}
Rifle::Rifle(){}
Rifle::~Rifle(){}


//Monster Class

Monster::Monster(char type, int x, int y, int hP, const string &name) : Character(type, x, y, hP), name(name) {}
Monster:: Monster(){}
Monster::~Monster(){}
const string & Monster:: getName() const {
    return name;
}
void Monster:: setName(const string &name) {
    this->name = name;
}

//GhostMonster class

GhostMonster::GhostMonster(char type, int x, int y, int hP, const string &name, bool isVisble) : Monster(type, x, y, hP,name),is_Visble(isVisble) {}
GhostMonster::GhostMonster(){}
GhostMonster::~GhostMonster(){}

bool GhostMonster::isVisble() const {
    return is_Visble;
}
void GhostMonster::setIsVisble(bool isVisble) {
    this->is_Visble = isVisble;
}

//TankMonster class

TankMonster::TankMonster(char type, int x, int y, int hP, const string &name, int shield) : Monster(type, x, y, hP,name),shield(shield) {}
TankMonster::TankMonster(){}
TankMonster::~TankMonster(){}
int TankMonster::getShield() const {
    return shield;
}
void TankMonster::setShield(int shield) {
    this->shield = shield;
}
void TankMonster:: reduceHp(int dmg){
   if (shield<=0)
       this->setHp(this->getHp()-dmg);
    else if (dmg<shield)
        this->setShield(this->getShield()-dmg);
    else if (dmg>=shield)
    {
        int s = shield;
       shield=0;
       this->setHp(this->getHp()-(dmg-s));
    }
}

//Item class

Item::Item(char type) : Object(type) {}
Item::Item(){}
Item::~Item(){}

//Ammo class

Ammo::Ammo(char type, int bullCollected) : Item(type), bullCollected(bullCollected) {}
Ammo::Ammo(){}
Ammo::~Ammo(){}

int Ammo::getBullCollected() const {
    return bullCollected;
}
void Ammo::setBullCollected(int bullCollected) {
    this->bullCollected = bullCollected;
}

//Potion class

Potion:: Potion(char type, int noHeal) : Item(type), noHeal(noHeal) {}
Potion:: Potion(){}
Potion:: ~Potion(){}

int Potion::getNoHeal() const {
    return noHeal;
}
void Potion::setNoHeal(int noHeal) {
    this->noHeal = noHeal;
}


//Game class

Game:: Game(){

    currHero = nullptr;
    // Initialize grid with empty objects

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            grid[i][j] = new Object('.');
        }
    }

}
//Game::Game(Object ***grid, Hero *currHero) : grid(grid),currHero(currHero) {}
Game:: ~Game(){
    // Deallocate memory for grid objects
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {

            delete grid[i][j];

        }
    }
    // Deallocate memory for hero object

}



int Game:: round=0;
int Game::getRows() const {
    return rows;
}
void Game::setRows(int rows) {
    Game::rows = rows;
}
int Game::getCols() const {
    return cols;
}
void Game::setCols(int cols) {
    Game::cols = cols;
}

Hero *Game::getCurrHero() const {
    return currHero;
}

void Game::setCurrHero(Hero *currHero) {
    Game::currHero = currHero;
}

int randomX (){
    int randomNumber = rand() % 15;
    return randomNumber;
}
int randomY (){
    int randomNumber = rand() % 15;
    return randomNumber;
}

void Game:: GenerateMap(){

    // the initialization is already done in the constructor
    // but if that's not what's wanted, and it must be in generateMap
    // then here it is
    /*
    rows = 15;
    cols = 15;

    grid = new Object*[rows];
    for (int i = 0; i < rows; ++i) {
        grid[i] = new Object[cols];
    }
    */

    srand(static_cast<unsigned int>(std::time(0)));

    for (int i=0; i<rows; i++){
        for (int j=0; j<cols; j++)
            (grid[i][j])->setType('.');
    }
    (grid[0][0])->setType('O'); //identify it as Origin so no Ammo, Potion or Monsters can be located there

    for (int i=0; i<5; i++) {
        int x = randomX();
        int y = randomX();
        while ((grid[x][y])->getType() != '.') {
            x = randomX();
            y = randomX();
        }
        Potion* p= new Potion('P', 10 +rand() % 41);
        grid[x][y] = p;
    }

    for (int i=0; i<10; i++) {
        int x = randomX();
        int y = randomX();
        while ((grid[x][y])->getType() != '.') {
            x = randomX();
            y = randomX();
        }
        Ammo* a = new Ammo('A', 5 +(rand() % 16));
        grid[x][y] = a;

        //Ammo* aa = new Ammo ('A', 5 +(rand() % 16));
        //grid[x][y]=*aa;
    }

    for (int i=0; i<5; i++) {
        int x = randomX();
        int y = randomX();
        while ((grid[x][y])->getType() != '.') {
            x = randomX();
            y = randomX();
        }

        //Point z={x,y};
        string name = "Monster"+to_string(i);
        GhostMonster* g = new GhostMonster ('G', x, y, (rand() % 10) * 10 + 60, name, true);
        grid[x][y] = g;
    }

    for (int i=5; i<10; i++) {
        int x = randomX();
        int y = randomX();
        while ((grid[x][y])->getType() != '.') {
            x = randomX();
            y = randomX();
        }

        string name = "Monster"+to_string(i);
        TankMonster* t = new TankMonster ('T', x, y, (rand() % 10) * 10 + 60, name, 5);
        grid[x][y] = t;
    }

}

//phebe
ostream&  operator<<(ostream& os, const Object& o) {
    os << "Object type " << o.type << endl;
    return os;
}
ostream& operator<<(ostream& os,  Gun& gun){
    os << "Weapon Name: " << gun.getName() << endl;
    os << "Bullets: " << gun.getNoBullet() << endl;
    os << "Damage: " << gun.getDmg() << endl;
    os << "Range: " << gun.getRange() << endl;
    return os;
}


ostream& operator<<(ostream& os,  Hero& hero) {
    os << "Type: " << hero.getType() << endl;
    os << "Position: (" << hero.getX() << ", " << hero.getY() << ")" << endl;
    os << "Health Points: " << hero.getHp() << endl;

    if (hero.gun != nullptr) {
        os << *(hero.gun);
    } else {
        os << "No weapon equipped." << endl;
    }
    if (hero.getType()=='D' ) {
        DemolitionHero* dh = static_cast<DemolitionHero*>(&hero);
        os << *(dh->getExtra())<<endl;
    }
    else
        os <<endl;


    return os;
}
//main


void Game:: showMap(){
    for (int i=0; i<rows; i++){
        for (int j=0; j<cols; j++){
            if ((grid[i][j])->getType()=='G'&& !(static_cast<GhostMonster*>(grid[i][j])->isVisble()))
                cout << '.' << "  " ;
            else
            cout << (grid[i][j])->getType() << "  " ;
        }
        cout << endl;
    }
    cout << *currHero;
    cout << "Current round:"<<round << endl;
}
void Game:: startGame(){
    int t;
    while (true){
    cout << "Please enter 1 to choose Demolition or 2 to choose Medic"<<endl;
    cin >> t;
    if (t==1 || t==2)
        break;
    }
    int g;
    while (true){
    cout << "Please enter 3 to choose Pistol or 4 to choose Bazooka or 5 to choose Rifle"<<endl;
    cin >> g;
    if (g==3 || g==4 || g==5)
    break;}
    this->GenerateMap();
    int choice = t*g;

    switch(choice){
        case 3:{
            Pistol * p = new Pistol('S', "Pistol1");
            DemolitionHero* dH= new DemolitionHero('D', 0,0, 200, p);
            grid[0][0]=dH;
            currHero=dH;
            int n;
            while (true){

                cout << "Please enter 3 to choose Pistol or 4 to choose Bazooka or 5 to choose Rifle"<<endl;
                cin >> n;
                if (n==3 || n==4 || n==5)
                    break;}
               switch (n){
                case 3: dH->setExtra(new Pistol('S', "Pistol2"));break;
                case 4: dH->setExtra(new Bazooka('B', "Bazooka2"));break;
                case 5: dH->setExtra(new Rifle('R', "Rifle2"));break;

            }
            break;
        }
        case 4:{
            Bazooka * b = new Bazooka('B', "Bazooka1");
            DemolitionHero* dH= new DemolitionHero('D', 0,0, 200, b);
            grid[0][0]=dH;
            currHero=dH;
            int n;
            while (true){

                cout << "Please enter 3 to choose Pistol or 4 to choose Bazooka or 5 to choose Rifle"<<endl;
                cin >> n;
                if (n==3 || n==4 || n==5)
                    break;}
            switch (n){
                case 3: dH->setExtra(new Pistol('S', "Pistol2"));break;
                case 4: dH->setExtra(new Bazooka('B', "Bazooka2"));break;
                case 5: dH->setExtra(new Rifle('R', "Rifle2"));break;

            }
            break;
        }
        case 5:{
            Rifle * r = new Rifle('R', "Rifle1");
            DemolitionHero* dH= new DemolitionHero('D', 0,0, 200, r);
            grid[0][0]=dH;
            currHero=dH;
            int n;
            while (true){

                cout << "Please enter 3 to choose Pistol or 4 to choose Bazooka or 5 to choose Rifle"<<endl;
                cin >> n;
                if (n==3 || n==4 || n==5)
                    break;}
            switch (n){
                case 3: dH->setExtra(new Pistol('S', "Pistol2"));break;
                case 4: dH->setExtra(new Bazooka('B', "Bazooka2"));break;
                case 5: dH->setExtra(new Rifle('R', "Rifle2"));break;

            }
            break;
        }
        case 6:{
            Pistol * p = new Pistol('S', "Pistol1");
            MedicHero* mH= new MedicHero('M', 0,0, 200, p, 50);
            grid[0][0]=mH;
            currHero=mH;
            break;
        }
        case 8:{
            Bazooka * b = new Bazooka('B', "Bazooka1");
            MedicHero* mH= new MedicHero('M', 0,0, 200, b, 50);
            grid[0][0]=mH;
            currHero=mH;
            break;
        }
        case 10:{
            Rifle * r = new Rifle('R', "Rifle1");
            MedicHero* mH= new MedicHero('M', 0,0, 200, r, 50);
            grid[0][0]=mH;
            currHero=mH;
            break;
        }

    }
//testing

    this->showMap();
    cout << "Game is starting now"<<endl;

}


//SOME IMPORTANT NOTES !!!!!!

// In map: types:

// M is MedicHero
// D is DemolitionHero
// A is Ammo
// P is Potion
// G is GhostMonster
// T is TankMonster

// Regarding initialization:

// 1) Ammo, Potion, Monster : names in increasing form: Ammo1, Ammo 2
// 2) Monsters were given names in the form Monster0, Monster1, Monster2, same goes with guns
// 3) GhostMonster is_Visible is initialized with true
// 4) TankMonster shield is 5
// 5) hP is 200 for all
// 6) medicHero heal is 50
// 7) Demolition has no extra gun for now, if needed, either the other constructor would have to be called
// or the setExtra would be called and a new gun must be created using input from user.
// 8) We made is_Visible with an underscore so the getter is named "isVisible()" to avoid having same name of attribute and getter
// 9) Same thing was done with has_Extra so the getter can be named "hasExtra()"

// Destructors:

// 1) We implemented the destructor of Gun so Hero can call it in its own destructor
// 2) We implemented destructor of Map that calls the destructor of hero and delete the grid by first deleting each row
// and then deleting the array of pointers to the rows

// Extras (const):

// 1) any getter method is const to ensure it does not change anything
// 2) any structs or objects as parameters are taken as const references
// to avoid changing the value and avoid copying the object
// 3) getters of objects/struct return const references to avoid copying and changing values

//malak
Hero& Hero::operator+(const Ammo& a){

    this->gun->setNoBullet(this->gun->getNoBullet()+a.getBullCollected());
    if (this->getType()=='D')
    {
        DemolitionHero* d = static_cast<DemolitionHero*>(this);
        d->getExtra()->setNoBullet(d->getExtra()->getNoBullet()+a.getBullCollected());
    }
    return *(this);
}

Hero& Hero::operator+(const Potion& p){
    this->setHp(this->getHp()+p.getNoHeal());
    return *(this);
}
Hero& Hero::operator-( Monster& m){
    if (m.getType()=='T')
    {
        TankMonster* t= static_cast<TankMonster*>(&m);
        t->reduceHp(20);
    }
    else {
        m.setHp(m.getHp() - 20);
    }
    this->setHp(this->getHp()-10);
    return *(this);
}




void Game::move(Hero& h1 , char direction){
    int x = h1.getX();
    int y = h1.getY();
    int prev_x = x;
    int prev_y = y;
    switch (direction) {
        case 'w': x--; break;
        case 's':x++;break;
        case 'd': y++;break;
        case 'a': y--;break;
        default:
            cout<<"invalid direction. Please  enter direction";
            cin>>direction;
    }
    if(x < 0 || y < 0 || x > this->rows - 1 || y > this->rows - 1){
        cout<<"invalid move"<<endl;
        return;
    }
    if (grid[x][y]->getType() == 'A') {

        h1 = h1 + *(static_cast<Ammo*>(this->grid[x][y]));
        //delete grid[x][y];

    } else if (this->grid[x][y]->getType() == 'P') {
        h1 = h1 + *(static_cast<Potion*>(this->grid[x][y]));
    } else if (this->grid[x][y]->getType() == 'G' || this->grid[x][y]->getType() == 'T') {
        h1 = h1 - *(static_cast<Monster*>(this->grid[x][y]));
        Game::round++;
        //checkgameover
        return;
    }

    Object* b =  new Object('.');
    this->grid[prev_x][prev_y] = b;
    this->grid[x][y] = &h1;

    h1.setX(x);
    h1.setY(y);
    round++;
}

//phebe
void Game::FireGun(char direction) {
    if (currHero && currHero->getGun() == nullptr) {
        cout << "Hero does not have a gun" << endl;
        return;
    }
    if (currHero->getGun()->getNoBullet() <= 0){
        cout << "There is no bullets to fire" << endl;
        return;
    }

    int range = currHero->getGun()->getRange();
    int x = currHero->getX();
    int y = currHero->getY();
    int damage = currHero->getGun()->getDmg();

    for(int i = 0 ; i< range ; ++i) {
        switch (direction) {
            case 'w': x--; break;
            case 's': x++; break;
            case 'd': y++; break;
            case 'a': y--; break;
        }
        if (x < 0 || y < 0 || x >= rows || y >= cols) { //asumption, if not found and out of bounds, still fired
            cout << "Out of grid bounds" << endl;
            break;
        }
        if (grid[x][y]->getType() == 'G'||grid[x][y]->getType() == 'T') {

            Monster* monster = static_cast<Monster*>(grid[x][y]);

            if (monster->getType()=='T')
            {
                TankMonster* t= static_cast<TankMonster*>(monster);
                t->reduceHp(damage);
            }
            else
                monster->setHp(monster->getHp() - damage);

            if (monster->getHp() <= 0) {
                //in case of memory leakage
                grid[x][y] = new Object('.');
                //showMap();
            }
            break;
        }
    }

    currHero->getGun()->setNoBullet(currHero->getGun()->getNoBullet()-1);

    round++;
}

//sarah
void Hero:: useSpecial(){
        this->useSpecial();
}
void Gun:: useSpecial(Hero& h1 , Object* map[15][15]){
        h1.getGun()->useSpecial(h1, map);
}
void Pistol::useSpecial(Hero &h1, Object *map[15][15]) {

    if (this->getNoBullet()>=4)
        this->setNoBullet(this->getNoBullet()-4);
    else
        return;

    int x=h1.getX();
    int y=h1.getY();
    if (map[x+1][y]!=nullptr && (map[x+1][y]->getType()=='G' || map[x+1][y]->getType()=='T')) {
        Monster* monster = static_cast<Monster*>(map[x+1][y]);
        if (monster != nullptr) {
            if (monster->getType()=='T')
            {
                TankMonster* t= static_cast<TankMonster*>(monster);
                t->reduceHp(this->getDmg());
            }
            else
                monster->setHp(monster->getHp() - this->getDmg());

        }
    }
    if (x>0 && map[x-1][y]!=nullptr && (map[x-1][y]->getType()=='G'|| map[x-1][y]->getType()=='T')) {
        Monster* monster = static_cast<Monster*>(map[x-1][y]);
        if (monster != nullptr) {
            if (monster->getType()=='T')
            {
                TankMonster* t= static_cast<TankMonster*>(monster);
                t->reduceHp(this->getDmg());
            }
            else
                monster->setHp(monster->getHp() - this->getDmg());

        }
    }
    if (map[x][y+1]!=nullptr && (map[x][y+1]->getType()=='G'||map[x][y+1]->getType()=='T')) {
        Monster* monster = static_cast<Monster*>(map[x][y+1]);
        if (monster != nullptr) {
            if (monster->getType()=='T')
            {
                TankMonster* t= static_cast<TankMonster*>(monster);
                t->reduceHp(this->getDmg());
            }
            else
                monster->setHp(monster->getHp() - this->getDmg());
        }
    }
    if (y>0 && map[x][y-1]!=nullptr && (map[x][y-1]->getType()=='G'||map[x][y-1]->getType()=='M')) {
        Monster* monster = static_cast<Monster*>(map[x][y-1]);
        if (monster != nullptr) {
            if (monster->getType()=='T')
            {
                TankMonster* t= static_cast<TankMonster*>(monster);
                t->reduceHp(this->getDmg());
            }
            else
                monster->setHp(monster->getHp() - this->getDmg());
        }
    }
    // setNoBullet(getNoBullet()-4);
    Game::round++;
}

void Rifle::useSpecial(Hero &h1, Object *map[15][15]) {
    if (getNoBullet()<3)
        return;
    int hx=h1.getX();
    int hy=h1.getY();
    //up
    for (int i=1; i<=this->getRange(); i++){
        if (hx-i>=0 && map[hx-i][hy]!=nullptr && (map[hx-i][hy]->getType()=='T' ||map[hx-i][hy]->getType()=='G'))
        {

            Monster* temp=static_cast<Monster*>(map[hx-i][hy]);

            if (temp->getType()=='T')
            {
                TankMonster* t= static_cast<TankMonster*>(temp);
                t->reduceHp(this->getDmg());
            }
            else
                temp->setHp(temp->getHp() - this->getDmg());

        }
    }
    //left
    for (int i=1; i<=this->getRange(); i++){
        if (hy-i>=0 && map[hx][hy-i]!=nullptr && (map[hx][hy-i]->getType()=='T' ||map[hx][hy-i]->getType()=='G'))
        {
            Monster* temp=static_cast<Monster*>(map[hx][hy-i]);

            if (temp->getType()=='T')
            {
                TankMonster* t= static_cast<TankMonster*>(temp);
                t->reduceHp(this->getDmg());
            }
            else
                temp->setHp(temp->getHp() - this->getDmg());

        }
    }
    //right
    for (int i=1; i<=this->getRange(); i++){
        if (hy+i<=15 && map[hx][hy+i]!=nullptr && (map[hx][hy+i]->getType()=='T' ||map[hx][hy+i]->getType()=='G')  )
        {
            Monster* temp=static_cast<Monster*>(map[hx][hy+i]);

            if (temp->getType()=='T')
            {
                TankMonster* t= static_cast<TankMonster*>(temp);
                t->reduceHp(this->getDmg());
            }
            else
                temp->setHp(temp->getHp() - this->getDmg());


        }
    }
    setNoBullet(getNoBullet()-3);
    Game::round++;
}

void Bazooka::useSpecial(Hero &h1, Object *map[15][15]) {
    int x=h1.getX();
    int y=h1.getY();

    for (int i=0; i<15; i++){
        for (int j=0; j<15; j++){
            if (map[i][j]!=nullptr && (map[i][j]->getType()=='T'||map[i][j]->getType()=='G')){
                Monster* m = static_cast<Monster*>(map[i][j]);
                if (i-x == j-y||abs(x-i)==abs(y-j)){
                    delete map[i][j];
                    map[i][j] = new Object('.');
                }}
        }
    }
    Game::round++;
}

void MedicHero::useSpecial() {
    if (heal==0)
        cout << "cannot heal anymore"<<endl;
    else{
    setHp(getHp()+heal);
    heal=0;
    Game::round++;
    }
}
void DemolitionHero::useSpecial() {
    Gun* temp=getGun();
    setGun(extra);
    extra=temp;
    Game::round++;
}
void Game::useGunSpecial() {
    if (currHero->getGun()->getType()=='S' && currHero->getGun()->getNoBullet()>=4)
        currHero->getGun()->useSpecial(*currHero, grid);
    else if (currHero->getGun()->getType()=='R' && currHero->getGun()->getNoBullet()>=3)
        currHero->getGun()->useSpecial(*currHero, grid);
    else if (currHero->getGun()->getType()=='B' && (currHero->getX()==currHero->getY()||currHero->getX() + currHero->getY() == 14))
        currHero->getGun()->useSpecial(*currHero, grid);
    else
        cout << "cannot use special on gun"<<endl;

}

//TOQA
bool Game::foundMonster(){
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if(grid[i][j]->getType() == 'T' ||grid[i][j]->getType() == 'G' ){
                return true;
            }
        }
    }
    return false;
}

int Game::checkGameOver() {
    if (foundMonster() == false)
            return 1;
    else {
        if (currHero->getHp() == 0) {
            return 0;
        } else {
            return -1;
        }
        }

}
bool GhostMonster::status = true;
int Game:: oldRound=0;
void Game::updateMap(){
    //remove all dead Monsters from the map.
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if(grid[i][j]!=nullptr &&(grid[i][j]->getType() == 'T'||grid[i][j]->getType() == 'G' )){
                if((dynamic_cast<Monster*>(this->grid[i][j]))->getHp() <= 0){
                    //in case of memory leakage
                    delete grid[i][j];
                    grid[i][j]=new Object('.');
                }
            }
        }
    }
    //after every 3 turns
    if(round%3 == 0){
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if(grid[i][j]->getType() == 'G' ){
                    GhostMonster* g = dynamic_cast<GhostMonster*>(this->grid[i][j]);
                    if ( oldRound!=round){
                    g->setIsVisble(!(g->isVisble()));
                    GhostMonster:: status= !GhostMonster:: status;}
                }
            }
        }
        oldRound=round;
    }

    //after every 20 turns 1 monster of each type should be added
    if(round%20 == 0){
        int x = randomX();
        int y = randomX();
        while ((grid[x][y])->getType() != '.') {
            x = randomX();
            y = randomX();
        }

        string name = "Monsternew";
        TankMonster* t = new TankMonster ('T', x, y, (rand() % 10) * 10 + 60, name, 5);
        grid[x][y] = t;

        int a = randomX();
        int b = randomX();
        while ((grid[a][b])->getType() != '.') {
            a = randomX();
            b = randomX();

        }
        bool v = GhostMonster::status;
        GhostMonster* g = new GhostMonster ('G', a, b, (rand() % 10) * 10 + 60, name, v);
        grid[a][b] = g;


    }

   // showMap();
}






int main() {

    Game g;
    g.startGame();
   // int i=225;
    int check=-1;
    while (check==-1){
        char in;
        cout << "Please enter 'm' for move, 's' for shoot, 'g' for using gun's special ability or 'h' for hero's special ability"<<endl;
        cin >> in;
        while (in!='m'&& in!='s'&&in!='h'&&in!='g') {
            cout<< "Please enter 'm' for move, 's' for shoot, 'g' for using gun's special ability or 'h' for hero's special ability"<< endl;
            cin>> in;
        }
        switch(in){
            case'm':  {
                char dir;
                cout << "Move: enter s for south, w for north, a for west, d for east"<<endl;
                cin >> dir;
                while (dir!='s'&& dir!='w'&&dir!='a'&&dir!='d'){
                    cout << "Move: enter s for south, w for north, a for west, d for east"<<endl;
                    cin >> dir;
                }
                g.move(*g.getCurrHero(), dir);
                break;
            }
            case 's':{
                char dir;
                cout << "Fire: enter s for south, w for north, a for west, d for east"<<endl;
                cin >> dir;
                while (dir!='s'&& dir!='a'&&dir!='w'&&dir!='d'){
                    cout << "Fire: enter s for south, w for north, a for west, d for east"<<endl;
                    cin >> dir;
                }
                g.FireGun(dir);
                break;
            }
            case 'g':{
                g.useGunSpecial();
                break;
            }
            case 'h':{
                g.getCurrHero()->useSpecial();
                break;
            }


        }


        g.updateMap();

        check = g.checkGameOver();
        if (check==0){
            cout << "you lost, better luck next time"<<endl;
            break;}
        else if (check==1){
            cout << "Congratulations, you won"<<endl;
        break;}
        system("cls");

        g.showMap();
        //system("cls");


    }
   // g.useGunSpecial();
   // g.showMap();
    /*Game g;
    g.startGame();
    int i=3;
    while (i>0){

        g.showMap();

        cout <<g.checkGameOver()<<endl;
        i--;
    }*/


   // g.getCurrHero()->getHp();
   /* Hero h ('H', 0, 0, 100, new Gun('G', "g1", 5, 10, 3));
    Ammo a ('A', 10);
    Potion p ('P', 100);
    h=h+a;
    h=h+p;
    DemolitionHero dh ('H', 0, 0, 100, new Gun('G', "g1", 5, 10, 3), new Gun('G', "g2", 12, 7, 2));
    //cout << h.getGun()->getNoBullet()<<endl;
    //cout << h.getHp()<<endl;
    //dh=(DemolitionHero)(dh+a);
    //cout << dh.getGun()->getNoBullet();
    Monster m ('M', 9, 9, 25, "Monster1");
    //dh=(Hero)((Hero)dh-m);
    cout << dh.getHp()<< " "<< m.getHp()<<endl;*/
    /*DemolitionHero dh ('H', 0, 0, 100, new Gun('G', "g1", 5, 10, 3), new Gun('G', "g2", 12, 7, 2));
    Ammo a ('A', 10);
    DemolitionHero* temp =static_cast<DemolitionHero*>(&(dh+a));
    dh = *temp;
    cout << dh.getGun()->getNoBullet()<<endl;
    cout << dh.getExtra()->getNoBullet()<<endl;
    Object o ('H');
   // cout << o;
    Hero h ('H', 0, 0, 100, new Gun('G', "g1", 5, 10, 3));
    //cout << h;
    DemolitionHero dh ('D', 0, 0, 100, new Gun('G', "g1", 5, 10, 3), new Gun('G', "g2", 12, 7, 2));
    cout << dh;
    return 0;*/
    /*DemolitionHero dh ('D', 0, 0, 100, new Gun('G', "g1", 5, 10, 3), new Gun('G', "g2", 12, 7, 2));
    //cout << dh;
    dh.useSpecial();
    //cout << dh;
    MedicHero mH('M', 0,0, 200, new Rifle('R', "Rifle1"), 50);
    //cout << mH ;
    mH.useSpecial();
    //cout << mH ;
    Rifle* r = new Rifle('R', "Rifle1");*/

   return 0;
}
