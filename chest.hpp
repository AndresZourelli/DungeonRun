/*********************************************************************
** Program name: Final Project
** Author: Fabian Andres Zourelli
** Date: 12/10/2019
** Description: The header file for the chest file and describes needed data memebers
*********************************************************************/

#ifndef CHEST_H
#define CHEST_H
#include "space.hpp"
#include <stdlib.h>
class Chest : public Space
{
private:
    bool chest1 = false;
public:
    Chest();
    void item(Inventory *items);
    void item2(Inventory *items);
    void describeRoom(Person *person);
    void openChest(Person *p);
    ~Chest(){};
};

#endif