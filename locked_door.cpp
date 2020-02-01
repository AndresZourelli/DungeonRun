/*********************************************************************
** Program name: Final Project
** Author: Fabian Andres Zourelli
** Date: 12/10/2019
** Description: The implementation frile for the locked door header file and contains all the locked door logic
*********************************************************************/

#include "locked_door.hpp"

LockedDoor::LockedDoor(){
    space_type = "Locked Door";
}


void LockedDoor::item(Inventory *items){
    return;
}
void LockedDoor::describeRoom(Person *person){
    std::cout<<"-------------You entered another room!--------------------"<<std::endl;
    //while door isnt open ask user if they want to try
    if(!isItOpen()){

        std::cout<<"The door is locked... try to open?"<<std::endl;
        std::cout<<"1. Open door"<<std::endl;
        std::cout<<"2. Go back"<<std::endl;

        std::string input;

        getline(std::cin,input);

        while(!checkInput(input, 1,2)){
            std::cout<<"Please enter a valid option:"<<std::endl;
            getline(std::cin,input);
        }

        int isValid = std::stoi(input);

        if(isValid == 1){
            openDoor(person);
        }
    }else{
        std::cout<<"You already opened this door."<<std::endl;
    }
}
void LockedDoor::openDoor(Person *person){
    //check bag to see if we have key and if we do then open it
    Inventory *bag = person->getBackpack();
    if(bag->search("Key")){
        std::cout<<"Door is open"<<std::endl;
        changeOpen();
    }else{
        std::cout<<"You dont have the key yet."<<std::endl;
    }
    
}