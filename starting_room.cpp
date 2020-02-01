/*********************************************************************
** Program name: Final Project
** Author: Fabian Andres Zourelli
** Date: 12/10/2019
** Description: The implementation frile for the starting room header file and contains all the starting room logic
*********************************************************************/
#include "starting_room.hpp"

StartingRoom::StartingRoom(){
    space_type = "Starting Room";
}

void StartingRoom::describeRoom(Person *person){
    std::cout<<"-------------You entered the Starting room!--------------------"<<std::endl;
}

void StartingRoom::item(Inventory* items){
    items->addNode("Cursed Dragon Claw");
}