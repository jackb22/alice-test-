// main class.
// controls the overall flow and calls the other classes
// executes the game.
#include <iostream>
#include "Locations.h"
#include "Character.h"
#include "Inventory.h"


int main() {

    //test locations class
    SafeRoom* safeRoom = new SafeRoom();
    std::cout << safeRoom->getId() << std::endl; // Output: 4
    std::cout << safeRoom->getDescription() << std::endl; // Output: You find yourself in a small room with no exits. It seems safe here.
    std::cout << safeRoom->isSafe() << std::endl; // Output: true

    // testing character class
    Character* alice = new Character("Alice", 7, "female", 150, 3);;
    std::cout << alice->getName() << std::endl; // Output: Alice
    std::cout << alice->getHealth() << std::endl; // Output: 100
    alice->setHealth(50);
    std::cout << alice->getHealth() << std::endl; // Output: 50

    //test inventory class
    Inventory inventory(5);
    inventory.addItem("Potion");
    inventory.addItem("Key");
    inventory.addItem("Map");

    std::cout << "Max items: " << inventory.getMaxItems() << std::endl;

    // print the items in the inventory
    inventory.printItems();

    // remove an item from the inventory
    inventory.removeItem("Potion");

// print the items in the inventory
    inventory.printItems();

    return 0;
}


