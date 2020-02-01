/*********************************************************************
** Program name: Final Project
** Author: Fabian Andres Zourelli
** Date: 12/10/2019
** Description: The header file for the locked door file and describes needed data memebers
*********************************************************************/

#ifndef LOCKED_DOOR_H
#define LOCKED_DOOR_H
#include "space.hpp"

class LockedDoor : public Space
{
private:
    bool isLocked = true;

public:
    LockedDoor();
    void item(Inventory *items);
    void describeRoom(Person *person);
    void openDoor(Person *person);
    ~LockedDoor(){};
};
#endif