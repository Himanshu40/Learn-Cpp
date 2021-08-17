#include <iostream>
#include <vector>
#include <string>

// Used for test1
enum Direction {North, South, East, West};

// Used for test2
// Unscoped enumeration representing items for a grocery shopping list
enum GroceryItem {Milk, Bread, Apple, Orange};

// Used for test3
// Unscoped enumerations holding the possible states
// and sequences of a rocket launch.
enum State {EngineFailure, InclementWeather, Nominal, Unknown};
enum Sequence {Abort, Hold, Launch};

// enum Street {Main, North, Elm};             // Error, can't use North again

// Used for test1
// This function expects a Direction parameter
// and returns its string representation
std::string directionToString(Direction direction) {
    std::string result;

    switch (direction) {
        case North:
            result = "North";
            break;
        case South:
            result = "South";
            break;
        case East:
            result = "East";
            break;
        case West:
            result = "West";
            break;
        default:
            result = "Unknown direction";
    }

    return result;
}

// Overloading the stream insertion operator to insert
// the string representation of the provided GroceryItem
// parameter into the output stream
std::ostream &operator<<(std::ostream &os, GroceryItem groceryItem) {
    switch (groceryItem) {
        case Milk:
            os << "Milk";
            break;
        case Bread:
            os << "Bread";
            break;
        case Apple:
            os << "Apple";
            break;
        case Orange:
            os << "Orange";
            break;
        default:
            os << "Invalid item";
    }

    return os;
}

// Used for test2
// Returns a boolean depending on whether the GroceryItem
// parameter is a valid enumerator or not
bool isValidGroceryItem(GroceryItem groceryItem) {
    switch (groceryItem) {
        case Milk:
        case Bread:
        case Apple:
        case Orange:
            return true;
        default:
            return false;
    }
}

// Used for test3
std::istream &operator>>(std::istream &is, State &state) {
    std::underlying_type_t<State> userInput;
    is >> userInput;

    switch (userInput) {
        case EngineFailure:
        case InclementWeather:
        case Nominal:
        case Unknown:
            state = State(userInput);
            break;
        default:

            state = Unknown;
    }

    return is;
}

// It shows the use of an uscoped enumeration
void test1() {
    std::cout << "===TEST1===" << std::endl;

    Direction direction {North};
    std::cout << "\nDirection " << direction << std::endl;
    std::cout << directionToString(direction) << std::endl;

    direction = West;
    std::cout << "\nDirection " << direction << std::endl;
    std::cout << directionToString(direction) << std::endl;

    // direction = 5;      // Compiler Error
    direction = Direction(100);
    std::cout << "\nDirection " << direction << std::endl;
    std::cout << directionToString(direction) << std::endl;

    direction = static_cast<Direction>(100);
    std::cout << "\nDirection " << direction << std::endl;
    std::cout << directionToString(direction) << std::endl;
}

void displayGroceryItem(const std::vector<GroceryItem> &groceryList) {
    std::cout << "Grocery List" << "\n=========================" << std::endl;

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

    std::cout << "=========================" << std::endl;
    std::cout << "Valid items: " << validItemCount << std::endl;
    std::cout << "Invalid items: " << invalidItemCount << std::endl;
    std::cout << "Total items: " << validItemCount + invalidItemCount << std::endl;
}

// Using an unscoped enumeration to model grocery items
void test2() {
    std::cout << "===TEST2===" << std::endl;

    std::vector<GroceryItem> shoppingList;

    shoppingList.push_back(Apple);
    shoppingList.push_back(Apple);
    shoppingList.push_back(Milk);
    shoppingList.push_back(Orange);

    // GroceryItem item = 100;  // Compiler Error

    // Careful when casting
    int helicopter {1000};

    shoppingList.push_back(GroceryItem(helicopter));        // Invalid item
    shoppingList.push_back(GroceryItem(0));                 // Will add Milk again

    displayGroceryItem(shoppingList);
}

// Used for test3
std::ostream &operator<<(std::ostream &os, const Sequence sequence) {
    switch (sequence) {
        case Abort:
            os << "Abort";
            break;
        case Hold:
            os << "Hold";
            break;
        case Launch:
            os << "Launch";
            break;
    }

    return os;
}

// Used for test3
// Displays an informtion message given the sequence parameter
void initiate(Sequence sequence) {
    std::cout << "Initiate " << sequence << " sequence!" << std::endl;
}

// Using unscoped enums to control a rocket launch
void test3() {
    std::cout << "===TEST3===" << std::endl;
    
    State state;
    std::cout << "Launch state: ";
    std::cin >> state;

    switch (state) {
        case EngineFailure:
        case Unknown:
            initiate(Abort);
            break;
        case InclementWeather:
            initiate(Hold);
            break;
        case Nominal:
            initiate(Launch);
            break;
    }
}

int main() {
    test1();
    test2();
    test3();

    return 0;
}
