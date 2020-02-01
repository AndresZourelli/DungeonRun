/*********************************************************************
** Program name: Final Project
** Author: Fabian Andres Zourelli
** Date: 12/10/2019
** Description: The header file for the monster file and describes needed data memebers
*********************************************************************/
#ifndef MONSTER_H
#define MONSTER_H

#include "space.hpp"
#include <stdlib.h>

class Monster : public Space
{
private:
    int attack_damage = 10;
    int defense_armor = 5;
    int health = 30;

public:
    Monster();
    int attack();
    void defense(int person_attack);
    void item(Inventory *items);
    void describeRoom(Person *person);
    ~Monster(){};
};
#endif