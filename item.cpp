#include <iostream>
#include "item.h"

void Item::setName(char* newitem) {
    strcpy(name, newitem);
}

