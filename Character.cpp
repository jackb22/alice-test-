// represents all the characters in the game

//

#include "Character.h"
#include "Locations.h"
#include "Inventory.h"

#include <utility>
#include <fstream>
#include <sstream>
#include <iostream>

// Constructor that initializes the member variables using the input parameters.
//Character::Character(std::string name, int age, std::string gender, int size, int lives, int health, Locations* currentLocation)
//        : name(std::move(name)), age(age), gender(std::move(gender)), size(size), lives(lives), health(health), inventory(10), currentLocation(currentLocation)
//{}

// Constructor that initializes the member variables using the input parameters.
Character::Character(std::string name, int age, std::string gender, int size, int lives, int health, const Locations* currentLocation)
        : name(std::move(name)), age(age), gender(std::move(gender)), size(size), lives(lives), health(health), inventory(10), currentLocation(currentLocation)
{
    // Load items for the character from the items.txt file.
    std::vector<Items> items = Items::loadItemsFromFile("items.txt");
}
// Method that returns the character's name.
std::string Character::getName()
{
    return name;
}

// Method that returns the character's gender.
std::string Character::getGender()
{
    return gender;
}

// Method that returns the character's size.
int Character::getSize()
{
    return size;
}
// Method that returns the character's lives.
int Character::getLives()
{
    return lives;
}

// Method that changes the character's size by the input amount.

void Character::changeSize(int amount)
{
    size += amount;
}

// Method that sets the character's lives to the input amount.
void Character::setLives(int amount)
{
    lives = amount;
}
// Method that sets the character's health to the input amount.
void Character::setHealth(int newHealth) {
    health = newHealth;
}

// Method that sets the character's current location to the input location.
void Character::setCurrentLocation(Locations* location)
{
    currentLocation = location;
}


// Method that gets the character's current location to the input location.
Locations* Character::getCurrentLocation() const {
    return currentLocation;
}

// Method that returns the character's health.
int Character::getHealth() const {
    return health;
}

//move the character to a new location
void Character::moveTo(Locations* newLocation)
{
    currentLocation = newLocation;
}

bool Character::hasAccessTo(const std::string &locationName) {
//todo: implement this method after the inventory class is implemented
    // Check if the character's current location is the same as the input location
//    if (currentLocation->getName() == locationName) {
//        return true;
//    }

    // Check if the character has the location in their inventory
//    if (inventory.hasItem(locationName)) {
//        return true;
//    }

    // Check if the character has access to the location through another means (e.g. a key)
    // ...

    // If none of the above conditions are met, the character does not have access to the location
    return false;
};

// not sure if this is correct TODO: check this
bool Character::moveToLocation(Locations *location){
    return currentLocation->hasAccessTo(reinterpret_cast<std::string &>(location));
}

//Method to add an item to the character's inventory
void Character::addItemToInventory(const std::string &item) {
    inventory.addItem(item);
}

//Method to remove an item from the character's inventory
void Character::removeItemFromInventory(const std::string &item) {
    inventory.removeItem(item);
}

//Method to check if the character's inventory contains an item
bool Character::inventoryContainsItem(const std::string &item) const {
   return inventory.containsItem(item);
}

//Method to get the items in the character's inventory
const std::vector<std::string> &Character::getInventoryItems() const {
    return inventory.getItems();
}

//Method to print the items in the character's inventory
void Character::printInventoryItems() const {
    inventory.printItems();
}

//Method to load the characters from a file
std::vector<Character> Character::loadCharactersFromFile(const std::string& fileName, const std::vector<Locations>& locations) {
    std::vector<Character> characters;

    std::ifstream inputFile(fileName);
    if (!inputFile) {
        std::cerr << "Error opening file: " << fileName << std::endl;
        return characters;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        std::stringstream ss(line);

        std::getline(ss, name, ',');

        ss >> age;
        ss.ignore(1, ',');


        std::getline(ss, gender, ',');


        ss >> size;
        ss.ignore(1, ',');


        ss >> lives;
        ss.ignore(1, ',');


        ss >> health;
        ss.ignore(1, ',');

        std::string currentLocationName;
        std::getline(ss, currentLocationName, ',');
        const Locations* tempLocation = nullptr;
        for (const auto& loc : locations) {
            if (loc.getName() == currentLocationName) {
                tempLocation = &loc;
                break;
            }
        }

        Character newCharacter(name, age, gender, size, lives, health, tempLocation);
        characters.push_back(newCharacter);
    }

    inputFile.close();
    return characters;
}





// Alice
Character alice("Alice", 7, "female", 150, 3);

// White Rabbit
Character whiteRabbit("White Rabbit", 3, "male", 50, 1);

// Mouse
Character mouse("Mouse", 1, "male", 10, 1);

// Dodo
Character dodo("Dodo", 5, "male", 30, 1);

// Caterpillar
Character caterpillar("Caterpillar", 2, "male", 20, 1);

// Queen of Hearts
Character queenOfHearts("Queen of Hearts", 35, "female", 180, 5);

// King of Hearts
Character kingOfHearts("King of Hearts", 40, "male", 190, 5);

// Cheshire Cat
Character cheshireCat("Cheshire Cat", 10, "unknown", 50, 1);

// Mad Hatter
Character madHatter("Mad Hatter", 40, "male", 170, 3);

// Red Queen
Character redQueen("Red Queen", 30, "female", 160, 5);

