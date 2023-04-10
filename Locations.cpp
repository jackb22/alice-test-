//
// represent each location in the game
//

// added the following to Locations.h
//  new constructor, north, west, south, east pointers for player locations,
//  added a neighbor vector to the constructor to be able to set "doors" between rooms

#include "Locations.h"

#include <utility>
#include <iostream>


Locations::Locations(int id, std::string name, std::string description, std::vector<std::string> neighbours)
        : id_(id), name_(std::move(name)), description_(std::move(description)), neighbours_(std::move(neighbours))
{}

// getter for the id of the location
int Locations::getId() const {
    return id_;
}

const std::string& Locations::getName() const {
    return name_;
}

const std::string& Locations::getDescription() const {
    return description_;
}

// setter for the description of the location
void Locations::setDescription(const std::string& newDescription) {
    description_ = newDescription;
}

void Locations::addNeighbour(const std::string& neighbourName) {
    neighbours_.push_back(neighbourName);}

    // get the list of neighbouring locations
    const std::vector<std::string>& Locations::getNeighbours() const {
        return neighbours_;}


bool Locations::hasAccessTo(std::string& locationName) const {
    for (const auto& neighbour : neighbours_) {
        if (neighbour == locationName) {
            return true;
        }
    }
    return false;
}




// Child class for Room 1: Above Ground/Down the Rabbit Hole
RabbitHole::RabbitHole() : Locations(1, "Above Ground/Down the Rabbit Hole", "You have fallen down the rabbit hole and landed in a strange place.") {
    north = nullptr;
    south = new PoolOfTears();
    east = nullptr;
    west = nullptr;
}
void RabbitHole::doChallenge(Character* player) {
// todo implement the challenge logic
    //    std::cout << "You have fallen down a rabbit hole and landed in a dark room." << std::endl;
//    std::cout << "You see a table with a bottle labeled 'Drink Me' and a key on it." << std::endl;
//
//    // player chooses whether to drink potion or not
//    int choice;
//
//    do {
//        std::cout << "1. Drink the potion" << std::endl;
//        std::cout << "2. Leave the potion" << std::endl;
//        std::cin >> choice;
//    } while (choice < 1 || choice > 2);
//
//    switch (choice) {
//        case 1:
//            std::cout << "You drink the potion and shrink down to a tiny size." << std::endl;
//            std::cout << "You notice a small door in the room that you can now fit through." << std::endl;
//            break;
//        case 2:
//            std::cout << "You leave the potion and proceed to look around the room." << std::endl;
//            break;
//        default:
//            std::cout << "Invalid choice. Please enter a number between 1 and 2." << std::endl;
//            break;
//    }
//
//    // player chooses what to do next
//
//    do {
//        std::cout << "1. Look around the room for clues" << std::endl;
//        std::cout << "2. Try the door" << std::endl;
//        std::cout << "3. Quit the game" << std::endl;
//        std::cin >> choice;
//    } while (choice < 1 || choice > 3);
//
//    switch (choice) {
//        case 1:
//            std::cout << "You look around the room and notice a piece of paper on the ground." << std::endl;
//            std::cout << "The paper has a riddle on it: 'I am not alive, but grow; I don't have lungs, but need air; I don't have a mouth, but need water to live. What am I?'" << std::endl;
//            std::cout << "What is your answer?" << std::endl;
//
//            std::string answer;
//            std::cin >> answer;
//
//            if (answer == "fire") {
//                std::cout << "You hear a clicking sound and notice that the keyhole has opened." << std::endl;
//                player->addItem("key");
//            } else {
//                std::cout << "Nothing happens." << std::endl;
//            }
//            break;
//        case 2:
//            if (player->hasItem("key")) {
//                std::cout << "You unlock the door and progress to the next location." << std::endl;
//                player->removeItem("key");
//            } else {
//                std::cout << "The door is locked." << std::endl;
//            }
//            break;
//        case 3:
//            std::cout << "You quit the game." << std::endl;
//            return;
//        default:
//            std::cout << "Invalid choice. Please enter a number between 1 and 3." << std::endl;
//            break;
//    }
}

bool RabbitHole::isSafe() const {
    return false;
}


// Child class for Room 2: The Pool of Tears
PoolOfTears::PoolOfTears() : Locations(2, "The Pool of Tears", "You have swam through a pool of tears and ended up on a shore. You see a mouse nearby.") {
    north = nullptr;
    south = new CaucusRace();
    east = nullptr;
    west = nullptr;
}

void PoolOfTears::doChallenge(Character* player) {
    std::cout << "The mouse tells you a story about a curious little girl named Alice. You listen attentively and learn about the many strange things she encountered in Wonderland.\n";
    std::cout << "You need to swim across to get to the other side." << std::endl;
    // TODO: implement the challenge logic
}

bool PoolOfTears::isSafe() const {
    return false;
}

// Child class for Room 3: CaucusRace
CaucusRace::CaucusRace() : Locations(3, "The Caucus Race", "You come across a group of animals having a Caucus race. They invite you to join them.") {
    north = new PoolOfTears();
    south = new MushroomForest();
    east = new QueensCourt();
    west = nullptr;
}

void CaucusRace::doChallenge(Character* player) {
    std::cout << "You enter the caucus race." << std::endl;
    std::cout << "You need to finish the race to proceed." << std::endl;
    // TODO: implement the challenge logic
}

bool CaucusRace::isSafe() const {
    return false;
}

// Child class for Safe Room
SafeRoom::SafeRoom() : Locations(4, "The Safe Room", "You find yourself in a small room with no exits. It seems safe here.") {}

void SafeRoom::doChallenge(Character* player) {
    std::cout << "There is nothing to do in this room but wait for the next adventure to begin.\n";
    // TODO: implement the challenge logic
}

bool SafeRoom::isSafe() const {
    return true;
}

// Child class for Room 4: The Caterpillar's Mushroom Forest
MushroomForest::MushroomForest() : Locations(5, "The Caterpillar's Mushroom Forest", "You enter a forest filled with mushrooms. You see a caterpillar smoking a hookah.") {
    north = new CaucusRace();
    south = new PoolOfTears();
    east = nullptr;
    west = nullptr;
}

void MushroomForest::doChallenge(Character* player) {
    std::cout << "The Caterpillar asks you who you are. What do you say?\n";
    std::string name;
    std::getline(std::cin, name);
    std::cout << "The Caterpillar gives you some cryptic advice and disappears into a mushroom.\n";
    // TODO: implement the challenge logic
    // std::cout << "You enter the mushroom forest." << std::endl;
    //    std::cout << "You need to find the Caterpillar to proceed." << std::endl;
}

bool MushroomForest::isSafe() const {
    return false;
}



// Child class for Room 6: The Queen's Court
QueensCourt::QueensCourt() : Locations(6, "The Queen's Court", "You find yourself in the Queen's court.") {
    north = nullptr;
    south = nullptr;
    east = nullptr;
    west = new CaucusRace();
}
void QueensCourt::doChallenge(Character* player) {
    //  TODO Implement challenge logic
    // std::cout << "You enter the queen's court." << std::endl;
    //    std::cout << "You need to answer the queen's riddle to proceed." << std::endl;

}

bool QueensCourt::isSafe() const {
    return false; // Queen's Court is not a safe location
}


// Child class for Room 7: The Croquet Ground
CroquetGround::CroquetGround() : Locations(7, "The Croquet Ground", "You find yourself in a croquet ground with living flamingos and hedgehogs.") {
    north = new MushroomForest();
    south = new Wonderland();
    east = nullptr;
    west = nullptr;
}
void CroquetGround::doChallenge(Character* player) {
    //  Todo Implement challenge logic
}

bool CroquetGround::isSafe() const {
    return false; // Croquet Ground is not a safe location
}


// Child class for Room 8: Wonderland
Wonderland::Wonderland() : Locations(8, "Wonderland", "You find yourself in Wonderland.") {}

void Wonderland::doChallenge(Character* player) {
    //  Todo Implement challenge logic
}

bool Wonderland::isSafe() const {
    return false; // Wonderland is not a safe location
}






