/*********************************************************************
** Program name: Final Project
** Author: Fabian Andres Zourelli
** Date: 12/10/2019
** Description: The implementation frile for the space header file and contains all the space logic
*********************************************************************/

#include "space.hpp"


void Space::connectRooms(Space *top,Space *bottom,Space *left,Space *right){
    //connect rooms to pointers
    top_ptr = top;
    bottom_ptr = bottom;
    left_ptr = left;
    right_ptr = right;
}


bool Space::isItOpen(){
    //check if space is able to be opened
    return isOpen;
}

void Space::changeOpen(){
    //open item
    isOpen = true;
}

void Space::changePass(){
    //determine if we can pass
    ableToPass = true;
}
bool Space::canPass(){
    //change pass
    return ableToPass;
}

bool Space::alive(){
    //determine if  monster is alive
    return isAlive;
}

void Space::changeAlive(){
    //change to dead
    isAlive = false;
}

Space::~Space(){
    
}