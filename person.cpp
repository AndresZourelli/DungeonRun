/*********************************************************************
** Program name: Final Project
** Author: Fabian Andres Zourelli
** Date: 12/10/2019
** Description: The implementation frile for the person header file and contains all the person logic
*********************************************************************/

#include "person.hpp"

Person::Person()
{

    //call set up function
   setUp();
}


void Person::setUp(){
    //initialize linked list for inventory
    Inventory *pack = new Inventory();
    backpack = pack;
}

Inventory *Person::getBackpack(){
    //return pointer to linked list
    return backpack;
}

int Person::attacking()
{
    //damage from 0-max
    int damage = rand() % (attack + 1);
    return damage;
}

void Person::defending(int person_attack)
{
    //calculate damage taken
    int damage_taken = person_attack - defense;
    //if damage taken is negative change to zero
    if (damage_taken < 0)
    {
        damage_taken = 0;
    }
    //change health
    health = health - damage_taken;

    std::cout<<"The hero took "<<damage_taken<<" damage and now has "<<health<<" health"<<std::endl;
    //if health is negative change to zero
    if (health < 0)
    {
        health = 0;
    }
}

int Person::getHealth()
{
    return health;
}

void Person::foundSword()
{
    std::cout << "\n You found a sword, your attacks are 3 times stronger!" << std::endl;
    attack *= 3;
}
void Person::foundShield()
{
    defense *= 4;
    std::cout << "\n You found a shield, your defense is 4 times stronger!" << std::endl;
}

Person::~Person(){
    delete backpack;
}