/*********************************************************************
** Program name: Final Project
** Author: Fabian Andres Zourelli
** Date: 12/10/2019
** Description: The implementation frile for the inventory header file and contains all the inventory logic
*********************************************************************/

#include "inventory.hpp"


Inventory::Inventory(){
    head1=nullptr;
}
void Inventory::addNode(std::string item){
    //add node to linked list
    if(head1 == nullptr){
        head1 = new Linked(item);
    }else{
        Linked *temp_ptr = head1;
        while(temp_ptr->next != nullptr){
            temp_ptr = temp_ptr->next;
        }
        temp_ptr->next = new Linked(item);
    }
}

bool Inventory::search(std::string value){
    //search linked list for items
    Linked *temp_ptr = head1;
    if(temp_ptr == nullptr){
        std::cout<<"No items in inventory!"<<std::endl;
    }

    while(temp_ptr){
        if(temp_ptr->item_name == value){
            return true;
        }
        temp_ptr = temp_ptr->next;
    }
    return false;
}

void Inventory::showList(){
    //print lisnked list
    Linked *temp_ptr = head1;
    if(temp_ptr == nullptr){
        std::cout<<"No items in inventory!"<<std::endl;
    }
    int count = 1;
    std::cout<<"\nYou have the following items: \n"<<std::endl;
    while(temp_ptr){
        std::cout<< count <<"."<<temp_ptr->item_name<<std::endl;
        temp_ptr = temp_ptr->next;
    }
}

Inventory::~Inventory(){
    //delete inventory when done
    Linked *temp_ptr = head1;
    while(temp_ptr){
        Linked *garbage = temp_ptr;
        temp_ptr = temp_ptr->next;
        delete garbage;
        garbage = nullptr;
    }
}