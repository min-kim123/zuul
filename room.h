//room
#pragma once
#include <vector>
using namespace std;

class Room {
    public:
    char label[80];
    char description[80];

    void setLabel(char newlabel[80]);
    void setDescription(char newdescription[80]);
    char* getDescription();

    class Exit {
        char direction[10];
        Room *neighbor;
        
        vector<Exit*>exits;
        Exit *newexit = new Exit;
        void setExit(Exit *newexit);

    };
};



