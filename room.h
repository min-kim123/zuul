//room
#pragma once
#include <vector>
#include <unordered_map>
using namespace std;

class Room {
    public:
    char label[80];
    char description[80];

    void setLabel(char newlabel[80]);
    void setDescription(char newdescription[80]);
    char* getDescription();

//use a map for the exits instead of a vector
    unordered_map<char*, Room*>exits;
    void setExit(char*, Room*);
    Room* getNextRoom(char*);
    bool checkExit(char*);
};
