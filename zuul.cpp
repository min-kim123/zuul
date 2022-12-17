#include <iostream>
#include <cstring>
#include "room.h"
#include <vector>
using namespace std;


int main() {
  bool cont = true;
  char firstword[30];
  char secondword[30];
  char command[60];

  //CREATING ROOMS
  vector<Room*> rooms;

  Room *lifeOfPie = new Room;
  lifeOfPie->setLabel("Life of Pie");
  lifeOfPie->setDescription("You are in Life of Pie.!");
  rooms.push_back(lifeOfPie);

  Room *emergencyRoom = new Room;
  emergencyRoom->setLabel("Emergency Room");
  emergencyRoom->setDescription("You are in the Emergency Room");
  rooms.push_back(emergencyRoom);



  while (cont == true) {
    cin.getline(command,30);
    //if the command is equal to any of the commands that lead to a nextroom for the currentroom

    if (strcmp(command, "north") == 0) {

    }

  }



  return 0;
}