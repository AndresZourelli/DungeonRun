/*********************************************************************
** Program name: Final Project
** Author: Fabian Andres Zourelli
** Date: 12/10/2019
** Description: The header file for the space file and describes needed data memebers
*********************************************************************/

#ifndef SPACE_H
#define SPACE_H

#include <string>
#include <iostream>
#include "inventory.hpp"
#include "checkInput.hpp"
#include "space.hpp"
#include "person.hpp"

class Space
{
protected:
public:
    std::string space_type;
    std::string node_type;
    Space *top_ptr = nullptr;
    Space *bottom_ptr = nullptr;
    Space *left_ptr = nullptr;
    Space *right_ptr = nullptr;
    bool isOpen = false;
    bool ableToPass = true;
    bool isAlive = true;

    virtual bool alive();
    virtual void changeAlive();
    virtual int attack(){return 0;};
    virtual void defense(int person_attack){return;};
    virtual bool isItOpen();
    virtual void changeOpen();
    virtual bool canPass();
    virtual void changePass();
    virtual void item(Inventory *items) = 0;
    virtual void describeRoom(Person *person) = 0;
    virtual void connectRooms(Space *top, Space *bottom, Space *left, Space *right);
    virtual ~Space() = 0;
};

#endif