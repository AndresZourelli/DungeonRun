/*********************************************************************
** Program name: Final Project
** Author: Fabian Andres Zourelli
** Date: 12/10/2019
** Description: The implementation frile for the exit header file and contains all the exit logic
*********************************************************************/

#include "exit.hpp"

Exit::Exit(){
    space_type = "Exit";
}

void Exit::describeRoom(Person *person){
    std::cout<<"-------------You entered another room!--------------------\n"<<std::endl;
    std::cout<<"You have encounted the exit, You can leave the dungeon!"<<std::endl; 
}

void Exit::item(Inventory *items){
    return;
}