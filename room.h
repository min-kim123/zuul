//room
#include "exit.h"
using namespace std;

class Room {
    public:
    char label[80];
    char description[80];
    void setLabel(char newlabel[80]);
    void setDescription(char newdescription[80]);


//needs to be a vector of exits so that there can be multiple
    char* getDescription();
//every time you setExit you add whatever came in it to a vector
//vector of two types- or make a class of it
    vector<Exit*>exits;
    char direction[10];
    Room *neighbor;
    void setExit(char newdirection[10], Room *neighbor);


};