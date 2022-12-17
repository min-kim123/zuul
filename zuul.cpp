#include <iostream>
#include <cstring>
#include <string.h>
#include "room.h"
#include "item.h"
#include <vector>
using namespace std;


int main() {

    cout << "You are on NW 23rd Avenue in Portland, Oregon! Have fun!" << endl;

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
    Room *ERparking = new Room;
    ERparking->setLabel("Emergency Room Parking Lot");
    ERparking->setDescription("You are at the Emergency Room parking lot");
    rooms.push_back(ERparking);
    Room *littleBigBurger = new Room;
    littleBigBurger->setLabel("Little Big Burger");
    littleBigBurger->setDescription("You are at Little Big Burger. Have a burger!");
    rooms.push_back(littleBigBurger);
    Room *grassa = new Room;
    grassa->setLabel("Grassa");
    grassa->setDescription("You are at Grassa. Have some pasta!");
    rooms.push_back(grassa);
    Room *saltAndStraw = new Room;
    saltAndStraw->setLabel("Salt and Straw");
    saltAndStraw->setDescription("You are at Salt and Straw. Get some samples!");
    rooms.push_back(saltAndStraw);
    Room *caseStudyCoffee = new Room;
    caseStudyCoffee->setLabel("Case Study Coffee");
    caseStudyCoffee->setDescription("You are at Case Study Coffee. Get some coffee!");
    rooms.push_back(caseStudyCoffee);
    Room *fedEx = new Room;
    fedEx->setLabel("FedEx");
    fedEx->setDescription("You are at FedEx!");
    rooms.push_back(fedEx);
    Room *bambooSushi = new Room;
    bambooSushi->setLabel("Bamboo Sushi");
    bambooSushi->setDescription("You are at Bamboo Sushi. Have some sushi!");
    rooms.push_back(bambooSushi);
    Room *rehab = new Room;
    rehab->setLabel("Rehab");
    rehab->setDescription("You are at Legacy Rehabilitation Institute of Oregon!");
    rooms.push_back(rehab);
    Room *pineStateBiscuits = new Room;
    pineStateBiscuits->setLabel("Pine State Biscuits");
    pineStateBiscuits->setDescription("You are at Pine State Biscuits");
    rooms.push_back(pineStateBiscuits);
    Room *jackInTheBox = new Room;
    jackInTheBox->setLabel("Jack in the Box");
    jackInTheBox->setDescription("You are at Jack in the Box!");
    rooms.push_back(jackInTheBox);
    Room *khaoSoy = new Room;
    khaoSoy->setLabel("Khao Soy");
    khaoSoy->setDescription("You are at Khao Soy. Have some pasta!");
    rooms.push_back(khaoSoy);
    Room *potteryBarn = new Room;
    potteryBarn->setLabel("Pottery Barn");
    potteryBarn->setDescription("You are at Pottery Barn. Have some pasta!");
    rooms.push_back(potteryBarn);
    Room *snowPeak = new Room;
    snowPeak->setLabel("Snow Peak");
    snowPeak->setDescription("You are at Snow Peak. Have some pasta!");
    rooms.push_back(snowPeak);


    //NEIGHBORING ROOMS
    lifeOfPie->setExit("north", littleBigBurger);
    lifeOfPie->setExit("east", emergencyRoom);
    lifeOfPie->setExit("west", grassa);

    emergencyRoom->setExit("north", ERparking); 
    emergencyRoom->setExit("south", rehab);
    emergencyRoom->setExit("west", lifeOfPie);

    ERparking->setExit("north", bambooSushi);
    ERparking->setExit("south", emergencyRoom);

    littleBigBurger->setExit("north",jackInTheBox);
    littleBigBurger->setExit("south",lifeOfPie);

    grassa->setExit("north",khaoSoy);
    grassa->setExit("east",lifeOfPie);
    grassa->setExit("west",snowPeak);
    grassa->setExit("south",saltAndStraw);

    caseStudyCoffee->setExit("north", saltAndStraw);

    fedEx->setExit("west",saltAndStraw);

    bambooSushi->setExit("south",ERparking);
    bambooSushi->setExit("west",jackInTheBox);

    rehab->setExit("north", emergencyRoom);
    rehab->setExit("east", potteryBarn);

    pineStateBiscuits->setExit("east", jackInTheBox);

    jackInTheBox->setExit("east", bambooSushi);
    jackInTheBox->setExit("south", ERparking);

    khaoSoy->setExit("south", grassa);

    potteryBarn->setExit("west", rehab);

    snowPeak->setExit("east", grassa);


    bool cont = true;
    char command[30];
    Room *currentRoom = lifeOfPie;

    while (cont == true) {
        cout << currentRoom->description << endl;
        cout << "Exits ";
        

        cin.getline(command, 30);
        //iterate over the neighbors for the currentroom and stop when you get a match
        if (strcmp(currentRoom->direction, command) == 0) {
                currentRoom = currentRoom->neighbor;
        }
    }
    return 0;
}