/*********************************************************************
** Program name: Final Project
** Author: Fabian Andres Zourelli
** Date: 12/10/2019
** Description: The header file for the game file and describes needed data memebers
*********************************************************************/

#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>
#include "checkInput.hpp"
#include "inventory.hpp"
#include "chest.hpp"
#include "deadend.hpp"
#include "empty_room.hpp"
#include "exit.hpp"
#include "locked_door.hpp"
#include "monster.hpp"
#include "starting_room.hpp"
#include "space.hpp"
#include "person.hpp"

enum
{
    UP,
    DOWN,
    LEFT,
    RIGHT
};

class Game
{
private:
    Space *starting_ptr = nullptr;
    Space *current_pos = nullptr;
    bool atExit = false;
    int steps = 20;
    Person *person = nullptr;

public:
    void setupGame();
    void moveToNextRoom();
    void playGame();
    ~Game();
    void deleteNodes(Space *node, int direction, Space *prev = nullptr);
};
#endif