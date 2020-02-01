/*********************************************************************
** Program name: Final Project
** Author: Fabian Andres Zourelli
** Date: 12/10/2019
** Description: The implementation frile for the game header file and contains all the game logic
*********************************************************************/

#include "game.hpp"

void Game::setupGame()
{
    //create nodes
    Space *startingroom = new StartingRoom();
    Space *chest = new Chest();
    Space *chest2 = new Chest();
    Space *deadend = new Deadend();
    Space *deadend2 = new Deadend();
    Space *emptyroom = new EmptyRoom();
    Space *emptyroom2 = new EmptyRoom();
    Space *exit = new Exit();
    Space *lockeddoor = new LockedDoor();
    Space *monster = new Monster();
    Space *monster2 = new Monster();
    person = new Person();

    //connect rooms (top,bottom,left,right)
    startingroom->connectRooms(monster2, emptyroom, emptyroom2, nullptr);
    chest->connectRooms(nullptr, emptyroom2, nullptr, monster2);
    chest2->connectRooms(nullptr, deadend2, monster2, nullptr);
    deadend->connectRooms(nullptr, nullptr, emptyroom, nullptr);
    deadend2->connectRooms(chest2, nullptr, nullptr, nullptr);
    emptyroom->connectRooms(startingroom, nullptr, monster, deadend);
    emptyroom2->connectRooms(chest, lockeddoor, nullptr, startingroom);
    exit->connectRooms(lockeddoor, nullptr, nullptr, nullptr);
    lockeddoor->connectRooms(emptyroom2, exit, nullptr, monster);
    monster->connectRooms(nullptr, nullptr, lockeddoor, emptyroom);
    monster2->connectRooms(nullptr, startingroom, chest, chest2);

    //track positions
    current_pos = startingroom;
    starting_ptr = startingroom;

    //enter first room
    std::cout << std::endl;
    current_pos->describeRoom(person);
    std::cout << std::endl;

    return;
}

void Game::playGame()
{
    std::cout << "\n Welcome to Dungeon Explorer!" << std::endl;
    std::cout << "\n The goal of this game is to search the dungeon for a key and successfully exit!" << std::endl;
    std::cout << "This is a dungeon... so be on the look out for monster, chests, locked doors and who knows what else." << std::endl;
    std::cout << "Oh and before you go this dungeon is every unstable so you will only get to about 20 rooms before it collapses." << std::endl;
    std::cout << "Good Luck!" << std::endl;

    //set up games
    setupGame();

    //make sure all conditions are met
    while (!atExit && steps != 0 && person->getHealth()>0)
    {
        //ask user to move to next room
        moveToNextRoom();
        //if at exit exit
        if(atExit){
            return;
        }
        steps--;
    }
}

void Game::moveToNextRoom()
{
    //track space
    Space *temp_location_ptr = nullptr;
    //make sure we have the life to continue
    if(person->getHealth()<=0){
        return;
    }
    std::cout << "\nWhat direction would you like to go?" << std::endl;
    std::cout << "1. Up" << std::endl;
    std::cout << "2. Down" << std::endl;
    std::cout << "3. Left" << std::endl;
    std::cout << "4. Right" << std::endl;

    std::string input;
    getline(std::cin, input);

    while (!checkInput(input, 1, 4))
    {
        std::cout << "Please enter a valid direction" << std::endl;
        getline(std::cin, input);
    }
    int direction = std::stoi(input) - 1;

    
    bool canPass = false;

    //if we are able to pass then continue
    while (!canPass)
    {
        //check users desired direction
        switch (direction)
        {
        case UP:
        {
            temp_location_ptr = current_pos->top_ptr;
            break;
        }
        case DOWN:
        {
            temp_location_ptr = current_pos->bottom_ptr;
            break;
        }
        case LEFT:
        {
            temp_location_ptr = current_pos->left_ptr;
            break;
        }
        case RIGHT:
        {
            temp_location_ptr = current_pos->right_ptr;
            break;
        }
        }
        //if not valid then ask for another
        if (temp_location_ptr == nullptr)
        {

            std::cout << "\n Whoops, looks like there is a wall there... Please choose another direction" << std::endl;
            std::cout << "1. Up" << std::endl;
            std::cout << "2. Down" << std::endl;
            std::cout << "3. Left" << std::endl;
            std::cout << "4. Right" << std::endl;

            std::string input2;
            getline(std::cin, input2);

            while (!checkInput(input2, 1, 4))
            {
                std::cout << "Please enter a valid direction" << std::endl;
                getline(std::cin, input2);
            }
            direction = std::stoi(input2) - 1;
            //if location is door but have no key make player go another direction
        }else if(temp_location_ptr->space_type == "Locked Door" && !person->getBackpack()->search("Key")){
            std::cout << "\n You can't go this direction the door is locked..." << std::endl;
            std::cout << "1. Up" << std::endl;
            std::cout << "2. Left" << std::endl;
            std::cout << "3. Right" << std::endl;

            std::string input2;
            getline(std::cin, input2);

            while (!checkInput(input2, 1, 3))
            {
                std::cout << "Please enter a valid direction" << std::endl;
                getline(std::cin, input2);
            }
            direction = std::stoi(input2) - 1;
            //convert direction because of removal of option
            if(std::stoi(input2) >= 2){
                direction+=1;
            }
            //if exit encountered exit
        }else if(temp_location_ptr->space_type == "Exit"){
            current_pos = temp_location_ptr;
            current_pos->describeRoom(person);

            std::cout<<"Congrats on surviving the dungeon and thanks for playing!"<<std::endl;
            atExit=true;
            return;
        }
        else
        {
            canPass = true;
        }
    }

    //change location
    current_pos = temp_location_ptr;
    std::cout<<"\n------------------------------------------"<<std::endl;
    std::cout<<"\nSteps left: "<< steps<<"\n"<<std::endl;
    //move to new room
    current_pos->describeRoom(person);
}

void Game::deleteNodes(Space *node, int direction = RIGHT, Space *prev2)
{
    //delete nodes on graph
    if (node == nullptr)
    {
        return;
    }
    Space *prev = prev2;

    if(node != prev){
        deleteNodes(node->top_ptr, UP, prev);
    }
    if(node != prev){
        deleteNodes(node->bottom_ptr,UP, prev);
    }
    if(node != prev){
        deleteNodes(node->left_ptr,UP, prev);
    }
    if(node != prev){
        deleteNodes(node->right_ptr,UP, prev);
    }
    // if (direction == UP)
    // {
    //     deleteNodes(node->top_ptr, UP);
    //     deleteNodes(node->right_ptr, RIGHT);
    //     deleteNodes(node->left_ptr, LEFT);
    // }
    // else if (direction == DOWN)
    // {
    //     deleteNodes(node->top_ptr, DOWN);
    //     deleteNodes(node->right_ptr, RIGHT);
    //     deleteNodes(node->left_ptr, LEFT);
    // }
    // else if (direction == LEFT)
    // {
    //     deleteNodes(node->right_ptr, LEFT);
    //     deleteNodes(node->top_ptr, UP);
    //     deleteNodes(node->top_ptr, DOWN);
    // }
    // else if (direction == RIGHT)
    // {
    //     deleteNodes(node->left_ptr, RIGHT);
    //     deleteNodes(node->top_ptr, UP);
    //     deleteNodes(node->top_ptr, DOWN);
    // }

    if(node!=nullptr){

        delete node;
        node = nullptr;
    }
}

Game::~Game()
{
    //deleteNodes(starting_ptr, UP, nullptr);
    Space *startingroom = starting_ptr;
    Space *chest = starting_ptr->left_ptr->top_ptr;
    Space *chest2 = starting_ptr->top_ptr->right_ptr;
    Space *deadend = starting_ptr->bottom_ptr->right_ptr;
    Space *deadend2 = starting_ptr->top_ptr->right_ptr->bottom_ptr;
    Space *emptyroom = starting_ptr->bottom_ptr;
    Space *emptyroom2 = starting_ptr->left_ptr;
    Space *exit = starting_ptr->left_ptr->bottom_ptr->bottom_ptr;
    Space *lockeddoor = starting_ptr->left_ptr->bottom_ptr;
    Space *monster = starting_ptr->top_ptr;
    Space *monster2 = starting_ptr->bottom_ptr->left_ptr;

    delete exit;
    delete deadend2;
    delete deadend;
    delete lockeddoor;
    delete chest2;
    delete monster2;
    delete chest;
    delete emptyroom2;
    delete emptyroom;
    delete monster;
    delete startingroom;
    delete person;
    
}