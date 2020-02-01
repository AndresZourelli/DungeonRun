/*********************************************************************
** Program name: Final Project
** Author: Fabian Andres Zourelli
** Date: 12/10/2019
** Description: The implementation frile for the monster header file and contains all the monster logic
*********************************************************************/

#include "monster.hpp"

Monster::Monster()
{
    space_type = "Monster";
}

int Monster::attack()
{
    //damage from 0-max
    int damage = rand() % (attack_damage + 1);
    return damage;
}

void Monster::defense(int person_attack)
{
    //calculate damage taken
    int damage_taken = person_attack - defense_armor;
    //if damage taken is negative change to zero
    if (damage_taken < 0)
    {
        damage_taken = 0;
    }
    //change health
    health = health - damage_taken;

    std::cout<<"The monster took "<<damage_taken<<" damage and now has "<<health<<" health"<<std::endl;
    //if health is negative change to zero
    if (health < 0)
    {
        health = 0;
    }
}

void Monster::describeRoom(Person *person)
{
    std::cout << "\n-------------You entered another room!--------------------\n"
              << std::endl;

    if (isAlive)
    {

        std::cout << "You have encountered a monster, and now you must defeat it!" << std::endl;
        while (person->getHealth() > 0 && health > 0)
        {
            //person attacks first
            int person_attack = person->attacking();
            defense(person_attack);

            //monster attacks
            int monster_attack = attack();
            person->defending(monster_attack);
            std::cout<<std::endl;
        }
        //check who won the fight
        if (person->getHealth() <= 0)
        {
            std::cout << "Looks like the monster killed you....." << std::endl;
            std::cout << "Better luck next time." << std::endl;
            return;
        }
        else if (health <= 0)
        {
            std::cout << "Congrats, you have defeated the monster!" << std::endl;
            //change monster status
            changeAlive();
            //get items
            Inventory *p = person->getBackpack();
            item(p);
        }
    }
    else
    {
        std::cout << "Looks like you've already defeated this monster." << std::endl;
    }
}

void Monster::item(Inventory *items)
{
    //add item to list
    std::cout << "\nWhile rummaging through the monster's corpse you found a key." << std::endl;
    std::cout << "Key has been added to your inventory" << std::endl;
    items->addNode("Key");
}