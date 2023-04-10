//
// Created by Jack Bennett on 2023-03-02.
//
#ifndef ALICE_AND_WONDERLAND_ITEMS_H
#define ALICE_AND_WONDERLAND_ITEMS_H

#include "Inventory.h"
#include "Character.h"
#include "Locations.h"
#include <vector>
#include <string>

/**
 * @brief manages all the items in the game and their location.
 */
class Items {
private:
    std::string itemName;
    std::vector<std::string> itemDescriptions;
    std::vector<std::string> itemLocations;

public:
    /**
    * @brief Constructs a new Items object with the given name, descriptions, and locations.
    */
    Items(std::string name, const std::vector<std::string>& descriptions, const std::vector<std::string>& locations);


    /**
    * @brief Loads a list of items from a given file.
    *
    * The file should be in the format of one item per line, with each line having the following format:
    * "item name, description1|description2|...|descriptionN, location1|location2|...|locationM"
    *
    * @param fileName The name of the file to load the items from.
    * @return A vector containing all the items read from the file.
    */
    static std::vector<Items> loadItemsFromFile(const std::string& fileName);

    /**
     * @brief Gets the name of the item.
     * @return The name of the item.
     */
    const std::string &getName() const;

    /**
     * @brief Gets the descriptions of the item.
     * @return The descriptions of the item.
     */
    const std::vector<std::string> &getDescriptions() const;

    /**
     * @brief Gets the locations of the item.
     * @return The locations of the item.
     */
    const std::vector<std::string> &getLocations() const;

    /**
     * @brief Gets the description of the item at the given index.
     * @param index The index of the description to get.
     * @return The description of the item at the given index.
     */
    const std::string &getDescription(int index) const;

    /**
     * @brief Gets the location of the item at the given index.
     * @param index The index of the location to get.
     * @return The location of the item at the given index.
     */
    const std::string &getLocation(int index) const;
};

#endif //ALICE_AND_WONDER LAND_ITEMS_H