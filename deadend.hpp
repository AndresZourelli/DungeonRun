/*********************************************************************
** Program name: Final Project
** Author: Fabian Andres Zourelli
** Date: 12/10/2019
** Description: The header file for the deadend file and describes needed data memebers
*********************************************************************/

#ifndef DEADEND_H
#define DEADEND_H
#include "space.hpp"
class Deadend : public Space
{
private:
public:
    Deadend();
    void item(Inventory *items);
    void describeRoom(Person *person);
    ~Deadend(){};
};
#endif