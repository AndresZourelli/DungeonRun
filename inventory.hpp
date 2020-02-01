/*********************************************************************
** Program name: Final Project
** Author: Fabian Andres Zourelli
** Date: 12/10/2019
** Description: The header file for the inventory file and describes needed data memebers
*********************************************************************/
#ifndef INVENTORY_H
#define INVENTORY_H
#include <string>
#include <iostream>
class Inventory {
    private:
        struct Linked {
            public:
            Linked *next = nullptr;
            std::string item_name;
            Linked(std::string item, Linked *next1=nullptr){
                item_name = item;
                next = next1;
            }
        };
        Linked *head1=nullptr;
    public:
        Inventory();
        void addNode(std::string item);
        void showList();
        bool search(std::string value);
        ~Inventory();
        
};

#endif