#include <iostream>
#include "room.h"
#include <string.h>
#include <vector>
#include <iterator>
#include <unordered_map>
using namespace std;

void Room::setLabel(char *newlabel) {
    strcpy(label, newlabel);
}

void Room::setDescription(char *newdescription) {
    strcpy(description, newdescription);
}

char* Room::getDescription() {
    return description;
}

void Room::setExit(char* direction, Room* exit) {
    pair<char*, Room*> objPair(direction, exit);
    exits.insert(objPair);
}


//loop through every instance of map for the current room and return the direction for 
bool Room::checkExit(char *command) {
    int count = 0;
    unordered_map<char*,Room*>::iterator it;

    for (it = exits.begin(); it != exits.end(); ++it) {
        for (int i = 0; i < 2; ++i){
            if (it->first[i] == command[i]) {
                count+=1;
            }
        }
        if (count >= 2) {//if first 2 letters of the command match with one of the values for map return true
            return true;
        }
    }
    return false;
}

Room* Room::getNextRoom(char* command) {
    int count = 0;
    unordered_map<char*,Room*>::iterator it;
    for (it = exits.begin(); it != exits.end(); ++it) {
        for (int i = 0; i < 2; ++i){
            if (it->first[i] == command[i]) {
                count+=1;
            }
        }
        if (count >= 2) {//if first 2 letters of the command match with one of the values for map return true
            return it->second;
        }
    }
}

void Room::setItem(Item* newitem) {
    roomInventory.push_back(newitem);
}



void Room::printItems() {//trying to access memory i shouldnt??
    vector<Item*>::iterator it;
    for (it = roomInventory.begin(); it < roomInventory.end(); ++it) 
    cout << (*it)->name << " ";
}

int Room::getInventorySize() {
    return roomInventory.size();
}

void Room::deleteItem(int itemIndex) {
    roomInventory.erase(roomInventory.begin() + itemIndex);
}