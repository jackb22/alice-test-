//
// represents all items in the game
//

// getter and setter for putting in the inventory


#include <fstream>
#include <sstream>
#include "Items.h"
#include <iostream>

// Constructor
Items::Items(std::string name, const std::vector<std::string>& descriptions, const std::vector<std::string>& locations){
    itemName = name;
    itemDescriptions = descriptions;
    itemLocations = locations;
}



std::vector<Items> Items::loadItemsFromFile(const std::string& fileName) {
    std::vector<Items> items;

    std::ifstream inputFile(fileName);
    if (!inputFile) {
        std::cerr << "Error opening file: " << fileName << std::endl;
        return items;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        std::stringstream ss(line);

        std::string itemName;
        std::getline(ss, itemName, ',');

        std::vector<std::string> itemDescriptions;
        std::string itemDescription;
        while (std::getline(ss, itemDescription, '|')) {
            itemDescriptions.push_back(itemDescription);
        }

        std::vector<std::string> itemLocations;
        std::string itemLocation;
        while (std::getline(ss, itemLocation, '|')) {
            itemLocations.push_back(itemLocation);
        }

        Items newItem(itemName, itemDescriptions, itemLocations);
        items.push_back(newItem);
    }

    inputFile.close();
    return items;
}


// Gets the name of the item.
const std::string& Items::getName() const
{
    return itemName;
}

// Gets the descriptions of the item.
const std::vector<std::string>& Items::getDescriptions() const
{
    return itemDescriptions;
}

// Gets the locations of the item.
const std::vector<std::string>& Items::getLocations() const
{
    return itemLocations;
}

// Gets the description of the item at the given index.
const std::string& Items::getDescription(int index) const
{
    return itemDescriptions[index];
}

// Gets the location of the item at the given index.
const std::string& Items::getLocation(int index) const
{
    return itemLocations[index];
}

// items in the game


// creating key
Items key("key", {"A key that can be used to open a door"}, {"room1"});

// creating potion
Items potion("potion", {"A potion"}, {"room1"});

// creating book
Items book("book", {"A book"}, {"room1"});





