/**
* @file Locations.h
* @brief Defines the Locations class and its derived classes representing different locations in Alice in Wonderland game.
* @author Jack Bennett
*/

#ifndef ALICE_AND_WONDERLAND_LOCATIONS_H
#define ALICE_AND_WONDERLAND_LOCATIONS_H


#include <string>
#include <vector>

// Forward declaration of Character class
class Character;

/**
 * @brief The Locations class is an abstract class representing a location in the game.
 * It contains the basic information of a location, such as its ID, name and description, as well as the functions
 * to handle challenges and check safety status of the location. It is inherited by different child classes representing
 * specific locations in the game.
 */
class Locations {
public:


    Locations* north;
    Locations* west;
    Locations* south;
    Locations* east;



     /**
     * @brief Constructs a new Locations object with the given ID, name, and description.
     * @param id The ID of the location.
     * @param name The name of the location.
     * @param description The description of the location.
     * @param neighbours The vector of neighbouring locations.
     */
    Locations(int id, std::string name, std::string description, std::vector<std::string> neighbours = {});


    /**
     * @brief Adds a neighbouring location to the current location.
     * @param neighbourName The name of the neighbouring location.
     */
    void addNeighbour(const std::string& neighbourName);

    /**
     * @brief Gets the list of neighbouring locations.
     * @return The vector of neighbouring locations.
     */
    const std::vector<std::string>& getNeighbours() const;

    /**
     * @brief Checks if the player has access to the location.
     * @param locationName The name of the location to check.
     * @return true if the player has access to the location, false otherwise.
     */
    bool hasAccessTo( std::string& locationName) const;

    /**
     * @brief Gets the ID of the location.
     * @return The ID of the location.
     */
    int getId() const;

    /**
     * @brief Gets the name of the location.
     * @return The name of the location.
     */
    const std::string& getName() const;

    /**
     * @brief Gets the description of the location.
     * @return The description of the location.
     */
    const std::string& getDescription() const;

    /**
     * @brief Sets the description of the location to the given string.
     * @param newDescription The new description of the location.
     */
    void setDescription(const std::string& newDescription);

    /**
     * @brief Performs a challenge specific to the location on the given player.
     * @param player The character object representing the player.
     */
    virtual void doChallenge(Character* player) = 0;

    /**
     * @brief Checks if the location is safe for the player.
     * @return true if the location is safe, false otherwise.
     */
    virtual bool isSafe() const = 0;



    /**
     * @brief Destroys the Locations object.
     */
    virtual ~Locations() {};

    // characters:
    void addCharacter(Character* character);

    void removeCharacter(Character* character);

    bool containsCharacter(Character* character) const;






private:
    int id_; // ID of the location
    std::string name_; // Name of the location
    std::string description_; // Description of the location
    std::vector<std::string> neighbours_; // Neighbouring locations
    std::vector<Character*> characters_; // Characters in the location TODO: IMPLEMENT THIS
};


/**
@brief The RabbitHole class is a child class of Locations representing the location "Above Ground/Down the Rabbit Hole".
It contains its own implementation of doChallenge() and isSafe() functions.
*/
class RabbitHole : public Locations {
public:
    /**
     * @brief Constructs a new RabbitHole object.
     */
    RabbitHole();

    /**
     * @brief Executes the challenge for this location.
     *
     * @param player a pointer to the current player Character object.
     */
    void doChallenge(Character* player) override;

    /**
     * @brief Determines if the RabbitHole is a safe location.
     *
     * @return true if the RabbitHole is safe, false otherwise.
     */
    bool isSafe() const override;
};

/** @breif Child class for Room 2: The Pool of Tears */
class PoolOfTears : public Locations {
public:
    /**
     * @brief Constructs a new PoolOfTears object.
     */
    PoolOfTears();

    /**
     * @brief Executes the challenge for this location.
     *
     * @param player a pointer to the current player Character object.
     */
    void doChallenge(Character* player) override;

    /**
     * @brief Determines if the PoolOfTears is a safe location.
     *
     * @return true if the PoolOfTears is safe, false otherwise.
     */
    bool isSafe() const override;
};

/** @breif Child class for Room 3: The Caucus Race */
class CaucusRace : public Locations {
public:
    /**
     * @brief Constructs a new CaucusRace object.
     */
    CaucusRace();

    /**
     * @brief Executes the challenge for this location.
     *
     * @param player a pointer to the current player Character object.
     */
    void doChallenge(Character* player) override;

    /**
     * @brief Determines if the CaucusRace is a safe location.
     *
     * @return true if the CaucusRace is safe, false otherwise.
     */
    bool isSafe() const override;
};

/** @breif Child class for Safe Room(4) */
class SafeRoom : public Locations {
public:
    /**
     * @brief Constructs a new SafeRoom object.
     */
    SafeRoom();

    /**
     * @brief Executes the challenge for this location.
     *
     * @param player a pointer to the current player Character object.
     */
    void doChallenge(Character* player) override;

    /**
     * @brief Determines if the SafeRoom is a safe location.
     *
     * @return true if the SafeRoom is safe, false otherwise.
     */
    bool isSafe() const override;
};

/** @breif Child class for Room 5: The Caterpillar's Mushroom Forest */
class MushroomForest : public Locations {
public:
    /**
     * @brief Constructs a new MushroomForest object.
     */
    MushroomForest();

    /**
     * @brief Executes the challenge for this location.
     *
     * @param player a pointer to the current player Character object.
     */
    void doChallenge(Character* player) override;

    /**
     * @brief Determines if the MushroomForest is a safe location.
     *
     * @return true if the MushroomForest is safe, false otherwise.
     */
    bool isSafe() const override;
};

/**  @breif Child class for Room 6: The Queen's Court */
class QueensCourt : public Locations {
public:
    QueensCourt();

    /**
     * @breif Executes the challenge for this location.
     * @param player the player character
     */
    void doChallenge(Character* player) override;

    /**
     * @breif Checks if this location is safe.
     * @return true if the location is safe, false otherwise
     */
    bool isSafe() const override;
};

/** Child class for Room 7: The Croquet Ground */
class CroquetGround : public Locations {
public:
    CroquetGround();

    /**
     * @breif Executes the challenge for this location.
     * @param player the player character
     */
    void doChallenge(Character* player) override;

    /**
     * @breif Checks if this location is safe.
     * @return true if the location is safe, false otherwise
     */
    bool isSafe() const override;
};

/** @breif Child class for Room 8: Wonderland */
class Wonderland : public Locations {
public:
    Wonderland();

    /**
     * @breif Executes the challenge for this location.
     * @param player the player character
     */
    void doChallenge(Character* player) override;

    /**
     * @breif Checks if this location is safe.
     * @return true if the location is safe, false otherwise
     */
    bool isSafe() const override;
};


#endif //ALICE_AND_WONDERLAND_LOCATIONS_H
