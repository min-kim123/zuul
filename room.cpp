#include <iostream>
#include "room.h"
#include <string.h>
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

void Room::setExit(char *newdirection, Room *newneighbor) {
    strcpy(direction, newdirection);
    neighbor = newneighbor;

}