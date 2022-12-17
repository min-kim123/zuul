#include <iostream>
#include "room.h"
#include <string.h>
#include <vector>
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
