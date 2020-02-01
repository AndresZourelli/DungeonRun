/*********************************************************************
** Program name: Final Project
** Author: Fabian Andres Zourelli
** Date: 12/10/2019
** Description: The implementation frile for the empty room header file and contains all the empty room logic
*********************************************************************/

#include "empty_room.hpp"

EmptyRoom::EmptyRoom(){
    space_type = "Empty Room";
}

void EmptyRoom::describeRoom(Person *person){
    std::cout<<"-------------You entered another room!--------------------"<<std::endl;
    std::cout<<"This room appears empty...."<<std::endl;
}

void EmptyRoom::item(Inventory* item){
    return;
}