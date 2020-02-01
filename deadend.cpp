/*********************************************************************
** Program name: Final Project
** Author: Fabian Andres Zourelli
** Date: 12/10/2019
** Description: The implementation frile for the dead end header file and contains all the dead end logic
*********************************************************************/

#include "deadend.hpp"

Deadend::Deadend(){
    space_type = "Dead End";
}

void Deadend::describeRoom(Person *person){
    std::cout<<"-------------You entered another room!--------------------\n"<<std::endl;
    std::cout<<"Oh no, looks like you've reached a deadend!"<<std::endl;
}

void Deadend::item(Inventory *items){
    return;
}