/*********************************************************************
** Program name: Final Project
** Author: Fabian Andres Zourelli
** Date: 12/10/2019
** Description: The main function contains all the code for the final project.
*********************************************************************/

#include <iostream>
#include <string>
#include <stdlib.h>  
#include <time.h>
#include "game.hpp"
int main(int argc, char *argv[])
{
    srand(time(NULL));

    Game test;
    test.playGame();
    return 0;
}