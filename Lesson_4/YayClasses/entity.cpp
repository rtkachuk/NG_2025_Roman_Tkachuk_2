#include "entity.h"

Entity::Entity() {
    hp = 100;
    dmg = 10;
}

Entity::Entity(int hp_val, int dmg_val)
{
    hp = hp_val;
    dmg = dmg_val;
}

void Entity::makeDamage(int damage)
{
    hp -= damage;
}

void Entity::setHp(int newHp)
{
    // Ternary operation
    //

    hp = newHp > 100 ? hp : newHp;
}

void Entity::setDmg(int newDmg)
{
    dmg = newDmg > 80 ? dmg : newDmg;
}

void Entity::showEntityStatus() {
    cout << "HP: " << hp << ", DMG: " << dmg << endl;
}
