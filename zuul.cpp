#include <iostream>
#include <cstring>
#include <string.h>
#include "room.h"
#include <vector>
using namespace std;


int main() {
    cout << "You are on NW 23rd Avenue in Portland, Oregon! Collect all 5 items and drop them at FedEx!" << endl;
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

    //ITEMS
    Item *iceCream = new Item;
    iceCream->setName("icecream");
    saltAndStraw->setItem(iceCream);
    Item *coffee = new Item;
    coffee->setName("coffee");
    caseStudyCoffee->setItem(coffee);
    Item *pamphlet = new Item;
    pamphlet->setName("pamphlet");
    rehab->setItem(pamphlet);
    Item *bandaid = new Item;
    bandaid->setName("bandaid");
    emergencyRoom->setItem(bandaid);
    Item *pot = new Item;
    pot->setName("pot");
    potteryBarn->setItem(pot);

    char north[10] = "north";
    char east[10] = "east";
    char south[10] = "south";
    char west[10] = "west";

    //NEIGHBORING ROOMS
    lifeOfPie->setExit(north, littleBigBurger);
    lifeOfPie->setExit(east, emergencyRoom);
    lifeOfPie->setExit(west, grassa);

    emergencyRoom->setExit(north, ERparking); 
    emergencyRoom->setExit(south, rehab);
    emergencyRoom->setExit(west, lifeOfPie);

    ERparking->setExit(north, bambooSushi);
    ERparking->setExit(south, emergencyRoom);

    littleBigBurger->setExit(north,jackInTheBox);
    littleBigBurger->setExit(south,lifeOfPie);

    grassa->setExit(north,khaoSoy);
    grassa->setExit(east,lifeOfPie);
    grassa->setExit(west,snowPeak);
    grassa->setExit(south,saltAndStraw);

    caseStudyCoffee->setExit(north, saltAndStraw);

    fedEx->setExit(west,saltAndStraw);

    bambooSushi->setExit(south,ERparking);
    bambooSushi->setExit(west,jackInTheBox);

    rehab->setExit(north, emergencyRoom);
    rehab->setExit(east, potteryBarn);

    pineStateBiscuits->setExit(east, jackInTheBox);

    jackInTheBox->setExit(east, bambooSushi);
    jackInTheBox->setExit(south, ERparking);

    khaoSoy->setExit(south, grassa);

    potteryBarn->setExit(west, rehab);

    snowPeak->setExit(east, grassa);

    saltAndStraw->setExit(north, grassa);
    saltAndStraw->setExit(east, fedEx);
    saltAndStraw->setExit(south, caseStudyCoffee);

    //user inventory
    vector<Item*>userInventory;

    bool cont = true;
    char command[20];
    Room *currentRoom = lifeOfPie;//set current room to lifeOfPie
    char item[20]; 

    while (cont == true) {
        cout << endl <<currentRoom->description << endl;
        cout << "Item in this room: ";
        currentRoom->printItems();
        cout << endl;
        
        cout << "Enter a command (north, east, south, west, get, drop, inventory, quit): ";
        cin.getline(command, 20);
        
        //need to look through all the map instances within the map for the currentroom
        if (currentRoom->checkExit(command) == true) {//command is either north, east, south, or west
            currentRoom = currentRoom->getNextRoom(command);//currentroom becomes the nextroom corresponded with the exit
        }

        else if ((command[0] == 'g') && (command[1] == 'e')) {//GET ITEM
            //if there is only one item, get that, if not ask what item
            if (currentRoom->getInventorySize() == 0) {//no items in roomInventory
                cout << "No items in this room!" << endl;
            }
            else if (currentRoom->getInventorySize() == 1) {//one item in roomInventory
                //append first item from roomInventory to userInventory
                userInventory.push_back(currentRoom->roomInventory.front());
                cout << "Item has been added to your inventory!" << endl;
                //take out item from roomInventory
                currentRoom->deleteItem(0);
            }
            else {//multiple items in roomInventory
                cout << "Which item would you like to get: ";
                cin.getline(item, 20);
                currentRoom->whichItem(item);
                //if (currentRoom->whichItem(item)== true)//check if it exists and return
            }
        }
        
        else if ((command[0] == 'd') && (command[1] == 'r')) {//DROP ITEM
            if (userInventory.size() == 0) {//no items in userInventory
                cout << "No items in your inventory!" << endl;
            }
            else if (userInventory.size() == 1) {//one item in userInventory
                //drop the item
                userInventory.erase(userInventory.begin() + 0);
                cout << "Item has been dropped!" << endl;
            }
            else {//multiple items in userInventory
                cout << "Which item would you like to drop: ";
            }
            
        }
        else if (strcmp(command, "inventory") == 0) {
            cout << "---------------------------" << endl;
            cout << "User Inventory: " << endl;
        
            vector<Item*>::iterator it;
            for (it = userInventory.begin(); it < userInventory.end(); ++it) 
            cout << (*it)->name << " " << endl;
            cout << "---------------------------" << endl;
        }
        else if (strcmp(command, "quit") == 0) {//command is "quit"
            cont = false;
        }
        else {
            cout <<"Not sure what you mean" << endl;
        }
    }
    return 0;
}