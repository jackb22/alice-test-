# Alice_And_Wonderland

Just discovered: The items, characters, location descriptions and action words should be contained in separate text files, which are opened and loaded into the game at the start of the game. 
 What does this mean to you 

## Layout 

Room 1: Above Ground/Down the Rabbit Hole
Challenge: Follow the White Rabbit and find the rabbit hole.
Description: The White Rabbit appears and runs past Alice, muttering about being late. Alice decides to follow him and eventually finds a rabbit hole. The player must explore the area and find the correct rabbit hole to proceed.


Room 2: The Pool of Tears
Challenge: Find a way to shrink or grow to fit through different doorways.
Description: Alice falls into a pool of tears and meets a Mouse who is swimming nearby. She tries to engage the Mouse in conversation, but he is initially afraid of her. The player must find bottles with "Drink Me" labels or cakes with "Eat Me" labels to grow or shrink in size to fit through different doorways.

Room 3: The Caucus Race
Challenge: Understand and participate in the game of the Caucus Race.
Description: Alice meets the Dodo and other animals who are running in circles in a strange game called the Caucus Race. Alice tries to join in, but finds the rules confusing and the game difficult to follow. The player must try to understand the rules of the game and participate in it to progress.

Safe Room(4): Neutral area where Alice can rest and return to later in the game.
Challenge: None.
Description: This room serves as a safe haven where Alice can rest and recover. The Mad Hatter may appear and offer Alice a cup of tea.

Room 5: The Caterpillar's Mushroom Forest
Challenge: Understand the Caterpillar's riddles and prove Alice's identity.
Description: Alice meets the Caterpillar, who is sitting on top of a mushroom and smoking a hookah pipe. The Caterpillar speaks in riddles and questions Alice's identity. The player must solve the riddles and prove Alice's identity to proceed.

Room 6: The Queen's Court
Challenge: Navigate the rules of the game of live chess and avoid the Queen's wrath.
Description: Alice finds herself in the middle of a game of live chess, with the Queen of Hearts presiding over the proceedings. Alice sees a variety of characters in this room, including the Cheshire Cat, the Mad Hatter, and Tweedledee and Tweedledum. The player must navigate the rules of the game and avoid the Queen's wrath in order to progress.

Room 7: The Croquet Ground
Challenge: Play a chaotic and unpredictable game of croquet with the Red Queen.
Description: Alice finds herself on a croquet ground, where she must play a game with the Red Queen. The game is chaotic and unpredictable, with the playing pieces changing shape and size, and the other characters causing distractions and obstacles along the way.

Room 8: Wonderland
Challenge: Complete the final puzzles or challenges to reach the end of the game.
Description: This is where Alice completes her journey and finishes the game. The player may encounter elements from all the previous rooms, as well as some final puzzles or challenges to reach the end and complete the game.

Characters: 
Alice (main character)
White Rabbit
Mouse
Dodo
Caterpillar
Queen of Hearts
King of Hearts
Cheshire Cat
Mad Hatter
Red Queen


## Classes: 
### Game(Main class ) 
Invokes instance of the game and invokes game execution. 

### Characters: 

  The Character class represents a player or non-player character in the game. It contains attributes such as the character's name, gender, size,  number of lives, and health.  The class also includes methods for retrieving and modifying these attributes, such as getName(), getGender(), getSize(), getLives(), changeSize(), setLives(), and setHealth. 
 
  Characters: 
  White Rabbit
  Mouse
  Dodo
  Caterpillar
  Queen of Hearts
  King of Hearts
  Cheshire Cat
  Mad Hatter
  Red Queen

### locations
  Room 1 (above ground)
  Room 2 (pool of tears)
  Room 3 (the Caucus Race)
  Room 4 (safe room) 
  Room 5 (The Caterpillar's Mushroom Forest)
  Room 6 (The Queens Court)
  Room 7 (The Croquet Ground)
  Room 8 (Wonderland)

#### current implement methods:

Locations::Locations(): Constructor for the Locations class that initializes the locationIndex to 0 and adds four instances of Location to the locations vector.
void Locations::printLocations(): Method that prints out the names and descriptions of all the Location objects in the locations vector.
Location* Locations::getLocation(int index): Method that returns a pointer to the Location object at the specified index in the locations vector.
int Locations::getNumLocations(): Method that returns the number of Location objects in the locations vector.
Location::Location(std::string name, std::string description): Constructor for the Location class that initializes the name and description member variables.
std::string Location::getName(): Method that returns the name of the Location object.
std::string Location::getDescription(): Method that returns the description of the Location object.
void Location::setChallenge(Challenge* challenge): Method that sets the challenge associated with the Location object.
Challenge* Location::getChallenge(): Method that returns a pointer to the challenge associated with the Location object. If no challenge has been set, this method returns nullptr.


#### more methods to potentially  add to locations:
A function to add items to the location. This could be useful if you want certain items to be present in specific locations in the game.
A function to remove items from the location. This could be useful if you want items to disappear or be removed from a location after a certain event or action takes place.
A function to print out the items currently in the location.
A function to set and get the exits from the location. This could include functions like setNorthExit(Location* exit), setSouthExit(Location* exit), etc. You could also create a function like getExit(Direction direction) that takes a direction enum (e.g. NORTH, SOUTH, EAST, WEST) and returns the location that is in that direction from the current location.
A function to check whether a certain exit is locked or unlocked. You could create a bool variable for each exit direction to keep track of whether it is locked or unlocked, and create functions like setNorthExitLocked(bool locked) and isNorthExitLocked() to set and check the status of each exit.
A function to describe the current location, including any items that are present and the exits that are available.
A function to trigger an event or challenge in the location, such as a puzzle or obstacle that the player must solve or overcome before they can progress to the next location.


### Actions: 

### Inventory: 
holds items that the player has collected. 

####  Methods: 
Inventory(int maxItems) : Constructor that creates an Inventory object with the given maximum number of items.
void addItem(const std::string& item) : Method that adds an item to the inventory.
void removeItem(const std::string& item) : Method that removes an item from the inventory.
bool containsItem(const std::string& item) const : Method that checks if the inventory contains the given item.
const std::vector<std::string>& getItems() const : Method that returns the vector of items in the inventory.
int getMaxItems() const : Method that returns the maximum number of items the inventory can hold.
void printItems() const : Method that prints the items in the inventory.


### Control:





