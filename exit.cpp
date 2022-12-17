#include "room.h"
#include <vector>
#include <string.h>
using namespace std;

void Room::Exit::setExit(Exit *newexit) {
    exits.push_back(newexit);

}
