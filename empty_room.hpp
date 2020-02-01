/*********************************************************************
** Program name: Final Project
** Author: Fabian Andres Zourelli
** Date: 12/10/2019
** Description: The header file for the empty room file and describes needed data memebers
*********************************************************************/

#ifndef EMPTY_ROOM_H
#define EMPTY_ROOM_H
#include "space.hpp"
class EmptyRoom : public Space
{
public:
    EmptyRoom();
    void describeRoom(Person *person);
    void item(Inventory *item);
    ~EmptyRoom(){};
};
#endif