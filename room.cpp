#include <iostream>
#include "room.h"
#include <string.h>
#include <vector>
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
    cout << direction << ":" << exit->label << endl;
    exits.insert(objPair);
}


//loop through every instance of map for the current room and return the direction for 
bool Room::checkExit(char *command) {
    cout << "CHECKEXIT" << endl;
    int count = 0;
    unordered_map<char*,Room*>::iterator it;

    for (it = exits.begin(); it != exits.end(); ++it) {
        cout << it->first << ":" << it->second->label << endl;//

        for (int i = 0; i < 2; ++i){
            if (it->first[i] == command[i]) {
                cout <<"it i: "<<it->first[i] << " command i: " << command[i] << endl;//
                count+=1;
                cout << "count: " << count << endl;//
            }
        }
        if (count >= 2) {//if first 2 letters of the command match with one of the values for map return true
            cout << "true" << endl;//
            return true;
        }
    }
    cout << false << endl;
    return false;
}

Room* Room::getNextRoom(char* command) {
    cout << "GETNEXTROOM" << endl;
    int count = 0;
    unordered_map<char*,Room*>::iterator it;
    for (it = exits.begin(); it != exits.end(); ++it) {
        cout << it->first << ":" << it->second->label << endl;//
        for (int i = 0; i < 2; ++i){
            if (it->first[i] == command[i]) {
                cout <<"it i: "<<it->first[i] << " command i: " << command[i] << endl;//
                count+=1;
                cout << "count: " << count << endl;//
            }
        }
        if (count >= 2) {//if first 2 letters of the command match with one of the values for map return true
            return it->second;
        }
    }

}