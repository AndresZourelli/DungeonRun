/*********************************************************************
** Program name: Final Project
** Author: Fabian Andres Zourelli
** Date: 12/10/2019
** Description: The implementation frile for the chest header file and contains all the chest logic
*********************************************************************/
#include "chest.hpp"

Chest::Chest(){
    space_type = "Chest";
}

void Chest::describeRoom(Person *person){
    std::cout<<"-------------You entered another room!--------------------"<<std::endl;
    //if chest is open ask user if they want to open it
    if(!isItOpen()){

        std::cout<<"You've found a Chest! Open it to see whats inside."<<std::endl;
        std::cout<<"1. Open chest"<<std::endl;
        std::cout<<"2. Move on"<<std::endl;

        std::string input;

        getline(std::cin,input);

        while(!checkInput(input, 1,2)){
            std::cout<<"Please enter a valid option:"<<std::endl;
            getline(std::cin,input);
        }

        int isValid = std::stoi(input);

        if(isValid == 1){
            openChest(person);
            changeOpen();
        }
    }else{
        std::cout<<"\nYou already opened this chest."<<std::endl;
    }

}

void Chest::openChest(Person *p){
    //randomize prize of sword or shield
    int prize = rand()%2+1;
    Inventory *bag = p->getBackpack();
    std::cout<<"Opened Chest!"<<std::endl;
    if(prize==1){ 
        //add item to inventory and change stats
        item(bag);
        p->foundSword();

    }else{
        //add item to inventory and change stats
        item(bag);
        p->foundShield();
    }
    
}

void Chest::item(Inventory* items){
    items->addNode("The Hero's Sword");
}
void Chest::item2(Inventory* items){
    items->addNode("The Hero's Shield");
}
