#pragma once

#include <iostream>

using namespace std;

class Entity
{
public:
    Entity ();
    Entity (int hp_val, int dmg_val);
    void makeDamage(int damage);

    void setHp(int newHp);
    int getHp() { return hp; };

    void setDmg(int dmg);
    int getDmg() { return dmg; };

    void showEntityStatus();


private:
    int hp;
    int dmg;
};
