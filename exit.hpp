/*********************************************************************
** Program name: Final Project
** Author: Fabian Andres Zourelli
** Date: 12/10/2019
** Description: The header file for the exit file and describes needed data memebers
*********************************************************************/

#ifndef EXIT_H
#define EXIT_H

#include "space.hpp"

class Exit : public Space
{
private:
public:
    Exit();
    void item(Inventory *items);
    void describeRoom(Person *person);
    ~Exit(){};
};
#endif