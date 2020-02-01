/*********************************************************************
** Program name: Final Project
** Author: Fabian Andres Zourelli
** Date: 12/10/2019
** Description: The header file for the person file and describes needed data memebers
*********************************************************************/

#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
#include "inventory.hpp"
#include <stdlib.h>

class Person
{
private:
    int attack = 8;
    int defense = 2;
    int health = 15;
    Inventory *backpack;

public:
    Person();
    int attacking();
    void defending(int attack);
    int getHealth();
    void foundSword();
    void foundShield();
    Inventory *getBackpack();
    void setUp();
    ~Person();
};

#endif