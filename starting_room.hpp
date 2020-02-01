#ifndef STARTING_ROOM_H
#define STARTING_ROOM_H
#include "space.hpp"
class StartingRoom : public Space
{
public:
    StartingRoom();
    void item(Inventory *item);
    void describeRoom(Person *person);
    ~StartingRoom(){};
};
#endif