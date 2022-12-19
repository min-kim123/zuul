//room
#pragma once
#include <vector>
#include <unordered_map>
#include "item.h"
using namespace std;

class Room {
//ROOMS
    public:
    char label[80];//label for the room 
    char description[80];//descriptino for the room

    void setLabel(char newlabel[80]);
    void setDescription(char newdescription[80]);
    char* getDescription();

//EXITS
//unordered map of exits specific to each room
    unordered_map<char*, Room*>exits;

    void setExit(char*, Room*);
    Room* getNextRoom(char*);
    bool checkExit(char*);

//ITEMS
//vector of Items specific to each room
    vector<Item*>roomInventory;

    void setItem(Item*);
    void printItems();
    int getInventorySize();
    void deleteItem(int);
    //getItem
    //void dropitem-take out of user inventory, add to currentRoom inventory vector
    
};
