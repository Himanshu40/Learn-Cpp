#include <iostream>
#include <vector>

// Used for test1
// Scoped enumeration holding the items for a grocery list
// The value of the enumerator could be the itme code
enum class GroceryItem {Milk = 350, Bread = 250, Apple = 132, Orange = 100};

// Used for test1
std::ostream &operator<<(std::ostream &os, GroceryItem groceryItem) {
    std::underlying_type_t<GroceryItem> value = std::underlying_type_t<GroceryItem>(groceryItem);

    switch (groceryItem) {
        case GroceryItem::Milk:
            os << "Milk";
            break;
        case GroceryItem::Bread:
            os << "Bread";
            break;
        case GroceryItem::Apple:
            os << "Apple";
            break;
        case GroceryItem::Orange:
            os << "Orange";
            break;
        default:
            os << "Invalid Item!";
    }
    os << " : " << value;

    return os;
}

// Used for test1
bool isValidGroceryItem(GroceryItem groceryList) {
    switch (groceryList) {
        case GroceryItem::Milk:
        case GroceryItem::Bread:
        case GroceryItem::Apple:
        case GroceryItem::Orange:
            return true;
        default:
            return false;
    }
}

// Displays the grocery items in the grocery list
void displayGroceryList(const std::vector<GroceryItem> &groceryList) {
    std::cout << "\tGrocery List" << "\n============================" << std::endl;

    int invalidItemCount {0};
    int validItemCount {0};

    for (GroceryItem groceryItem : groceryList) {
        std::cout << groceryItem << std::endl;

        if (isValidGroceryItem(groceryItem)) {
            validItemCount++;
        }
        else {
            invalidItemCount++;
        }
    }

    std::cout << "\n============================" << std::endl;
    std::cout << "Valid items: " << validItemCount << std::endl;
    std::cout << "Invalid items: " << invalidItemCount << std::endl;
    std::cout << "Total items: " << validItemCount + invalidItemCount << std::endl;
}

// Using a scoped enumeration to model grocery items
void test1() {
    std::cout << "\t===TEST1===" << std::endl;

    std::vector<GroceryItem> shoppingList;

    shoppingList.push_back(GroceryItem::Apple);
    shoppingList.push_back(GroceryItem::Milk);
    shoppingList.push_back(GroceryItem::Orange);

    int helicopter {1000};

    // shoppingList.push_back(helicopter);
    shoppingList.push_back(GroceryItem(helicopter));
    shoppingList.push_back(GroceryItem(350));

    displayGroceryList(shoppingList);
}

// Used for test2
class Player {
        friend std::ostream &operator<<(std::ostream &os, const Player &p);
    public:
        enum class Mode {Attack, Defense, Idle};
        enum class Direction {North, South, East, West};

        Player(std::string name, Mode mode = Mode::Idle, Direction direction = Direction::North)
            : name {name}, mode {mode}, direction {direction} {}
        std::string getName() const { return name;}
        void setName(std::string name) {this->name = name;};

        Mode getMode() const {return mode;}
        void setMode(Mode mode) {this->mode = mode;}

        Direction getDirection() const {return direction;}
        void setDirection(Direction direction) {this->direction = direction;}
    private:
        std::string name;
        Mode mode;
        Direction direction;    
};

// Used for test2
// A simple function that returns the string representation
// of the Player::Mode parameter passed into it
std::string getPlayerMode(Player::Mode mode) {
    std::string result;

    switch (mode) {
        case Player::Mode::Attack:
            result = "Attack";
            break;
        case Player::Mode::Defense:
            result = "Defense";
            break;
        case Player::Mode::Idle:
            result = "Idle";
            break;
    }

    return result;
}

// Used for test2
// A simple function that returns the string representation
// of the Player::Direction parameter passed into it.
std::string getPlayerDirection(Player::Direction direction) {
    std::string result;

    switch (direction) {
        case Player::Direction::North:
            result = "North";
            break;
        case Player::Direction::South:
            result = "South";
            break;
        case Player::Direction::East:
            result = "East";
            break;
        case Player::Direction::West:
            result = "West";
            break;
    }

    return result;
}

// Overloading the output stream insertion operator
std::ostream &operator<<(std::ostream &os, const Player &p) {
    os << "Player Name: " << p.getName() << "\n"
       << "Player Mode: " << getPlayerMode(p.mode) << "\n"
       << "Player Direction: " << getPlayerDirection(p.direction)
       << std::endl;

    return os;
}

void test2() {
    std::cout << "\t===TEST2===" << std::endl;

    Player p1 {"Cloud Strife", Player::Mode::Attack, Player::Direction::North};
    Player p2 {"Tifa Lockhart", Player::Mode::Defense, Player::Direction::West};
    Player p3 {"Sephiroth", Player::Mode::Idle, Player::Direction::South};

    std::cout << p1 << std::endl;
    std::cout << p2 << std::endl;
    std::cout << p3 << std::endl;
}

int main() {
    // test1();
    test2();
    std::cout << std::endl;

    return 0;
}
