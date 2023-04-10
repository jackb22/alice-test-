//
// Created by Jack Bennett on 2023-03-02.
//

#include "Character.h"
#include "Locations.h"
#include <vector>

#ifndef ALICE_AND_WONDERLAND_INVENTORY_H
#define ALICE_AND_WONDERLAND_INVENTORY_H


/**
 * @brief The Inventory class represents the inventory of the player.
 */
class Inventory {
private:
    int maxItems; // max number of items the inventory can hold
    std::vector<std::string> items;  // the inventory is a vector of items

public:
    /**
     * @brief Constructs a new Inventory object with the given maximum number of items.
     * @param maxItems The maximum number of items the inventory can hold.
     */
    Inventory(int maxItems);

    /**
     * @brief Adds an item to the inventory.
     * @param item The item to add.
     */
    void addItem(const std::string& item);

    /**
     * @brief Removes an item from the inventory.
     * @param item The item to remove.
     */
    void removeItem(const std::string& item);

    /**
     * @brief Checks if the inventory contains an item.
     * @param item The item to check.
     * @return true if the inventory contains the item, false otherwise.
     */
    bool containsItem(const std::string& item) const;

    /**
     * @brief Gets the list of items in the inventory.
     * @return The vector of items in the inventory.
     */
    const std::vector<std::string>& getItems() const;

    /**
     * @brief Gets the maximum number of items the inventory can hold.
     * @return The maximum number of items the inventory can hold.
     */
    int getMaxItems() const;

    /**
     * @brief Prints the items in the inventory.
     */
    void printItems() const;
};


#endif //ALICE_AND_WONDERLAND_INVENTORY_H
