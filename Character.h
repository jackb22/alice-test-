/**
 * @breif defines the characters class and its methods
 * @file Character.h
 * @author Jack Bennett
 */

// make method that takes inventory.h

#ifndef ALICE_AND_WONDERLAND_CHARACTER_H
#define ALICE_AND_WONDERLAND_CHARACTER_H


#include <string>
#include "Locations.h"
#include "Items.h"
#include "Inventory.h"

class Character {
private:
    std::string name; // name of the character
    std::string gender; // gender of character
    int size; // size of the character
    int age; // age of the character
    int lives; // number of lives the character has
    int health; // health of the character
    Inventory inventory; // inventory of the character
    const Locations*  currentLocation; // current location of the character


public:

    /**
    * @brief Constructor for the Character class.
    * @param name The name of the character.
    * @param age The age of the character.
    * @param gender The gender of the character.
    * @param size The size of the character.
    * @param lives The number of lives the character has.
    * @param health The health of the character, default value is 100.
     * @param currentLocation The current location of the character, default value is RabbitHole.
    */
    Character(std::string name, int age, std::string gender, int size = 100 , int lives = 3, int health = 100, const Locations* currentLocation = new RabbitHole());


    /**
    * Get the name of the character.
    *
    * @return The name of the character.
    */
    std::string getName();

    /**
     * Get the gender of the character.
     *
     * @return The gender of the character.
     */

    std::string getGender();
    /**
     * Get the size of the character.
     *
     * @return The size of the character.
    */
    int getSize();

    /**
    * @brief Gets the age of the character.
    * @return The age of the character.
    */
    int getAge() const { return age; }

    /**
     * Get the number of lives the character has.
     *
     * @return The number of lives the character has.
     */
    int getLives();

    /**
    * Change the size of the character.
    *
    * @param amount The amount to change the size by.
    */
    void changeSize(int amount);

    /**
    * @breif get the current location of the character
    */
    Locations* getCurrentLocation() const;

    /**
     * @breif get the health of the character
     * @return health
     */
    int getHealth() const;

    /**
    * Set the number of lives the character has.
    *
    * @param amount The new number of lives for the character.
    */
    void setLives(int amount);

    /**
     * @breif set the health of the character
     */
     void setHealth(int health);


    /** @breif  set the current location of the character
     * @param location
     */
    void setCurrentLocation(Locations* location);

    /**
    * @breif Move the character to a new location.
    *
    * @param newLocation The new location to move to.
    */
    void moveTo(Locations* newLocation);

    /**
     * @breif Check if the character has access to a location.
     * @param locationName
     */
    bool hasAccessTo(const std::string& locationName);

    /**
     * @breif Moves the character to the specified location if it is accessible.
     * @param location The location to move to.
     * @return True if the character successfully moves to the location, false otherwise.
     */
    bool moveToLocation(Locations* location);


    /**
     * @brief Adds an item to the character's inventory.
     * @param item The name of the item to add.
     */
    void addItemToInventory(const std::string& item);

    /**
     * @brief Removes an item from the character's inventory.
     * @param item The name of the item to remove.
     */
    void removeItemFromInventory(const std::string& item);

    /**
     * @brief Checks if the character's inventory contains a specific item.
     * @param item The name of the item to check for.
     * @return True if the inventory contains the item, false otherwise.
     */
    bool inventoryContainsItem(const std::string& item) const;

    /**
     * @brief Returns a vector of the character's inventory items.
     * @return A vector of the character's inventory items.
     */
    const std::vector<std::string>& getInventoryItems() const;

    /**
     * @brief Prints the names of the items in the character's inventory.
     */
    void printInventoryItems() const;


    /**
     * @brief Loads a vector of characters from a file.
     * @param fileName The name of the file to load the characters from.
     * @return A vector of characters loaded from the file.
     */
    std::vector<Character> loadCharactersFromFile(const std::string& fileName, const std::vector<Locations>& locations);






    };


#endif //ALICE_AND_WONDERLAND_CHARACTER_H
