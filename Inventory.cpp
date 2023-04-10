//
// represents the inventory
//


#include "Inventory.h"
#include <iostream>

// remember to set the max number of items in the control class



// constructor
Inventory::Inventory(int maxItems) {
    this -> maxItems = maxItems;
}

// adds an item to the inventory
void Inventory::addItem(const std::string& item) {
    if (items.size() < maxItems) {
        items.push_back(item);
    } else {
        std::cout << "Inventory is full!" << std::endl;
    }
}

// removes an item from the inventory
void Inventory::removeItem(const std::string& item) {
    for (int i = 0; i < items.size(); i++) {
        if (items[i] == item) {
            items.erase(items.begin() + i);
            break;
        }
    }
}

// checks if the inventory contains an item
bool Inventory::containsItem(const std::string& item) const {
    for (int i = 0; i < items.size(); i++) {
        if (items[i] == item) {
            return true;
        }
    }
    return false;
}

// gets the list of items in the inventory
const std::vector<std::string>& Inventory::getItems() const {
    return items;
}

// gets the maximum number of items the inventory can hold
int Inventory::getMaxItems() const {
    return maxItems;
}

// prints the items in the inventory
void Inventory::printItems() const {
    std::cout << "Inventory contains: ";
    int numItems = items.size();
    for (int i = 0; i < numItems; i++) {
        std::cout << items[i];
        if (i == numItems - 1) {  // if  last item in the list
            std::cout << "." << std::endl;
        } else {
            std::cout << ", ";
        }
    }
}