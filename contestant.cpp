#include "contestant.h"
#include <iostream>
#include <string>

// default constructor
Contestant::Contestant() : numCodemons(0), numItems(0) {
    std::cout << "Enter contestant name: ";
    std::getline(std::cin, name);
}

// parameterized constructor
Contestant::Contestant(const std::string& name) : name(name), numCodemons(0), numItems(0) {
    if (name.empty()) {
        std::cout << "Enter contestant name: ";
        std::getline(std::cin, this->name);
    }
}

// copy constructor
Contestant::Contestant(const Contestant& other) : numCodemons(other.numCodemons), numItems(other.numItems) {
    std::cout << "Enter name for the cloned contestant: ";
    std::getline(std::cin, name);
    
    // copy pocket (Codemons)
    for (int i = 0; i < numCodemons; i++) {
        pocket[i] = other.pocket[i];
    }
    
    // copy backpack (Items)
    for (int i = 0; i < numItems; i++) {
        backpack[i] = other.backpack[i];
    }
}

// assignment operator
Contestant& Contestant::operator=(const Contestant& other) {
    if (this != &other) {
        name = other.name;
        numCodemons = other.numCodemons;
        numItems = other.numItems;
        
        // copy pocket (Codemons)
        for (int i = 0; i < numCodemons; i++) {
            pocket[i] = other.pocket[i];
        }
        
        // copy backpack (Items)
        for (int i = 0; i < numItems; i++) {
            backpack[i] = other.backpack[i];
        }
    }
    return *this;
}

// adds a Codemon to the pocket
bool Contestant::addCodemon(const Codemon& codemon) {
    // cheacks if we've reached the maximum number of Codemons
    if (numCodemons >= 10) {
        std::cout << "Cannot add more Codemons. Maximum limit reached." << std::endl;
        return false;
    }
    
    // checks for duplicate Codemon names
    for (int i = 0; i < numCodemons; i++) {
        if (pocket[i].getName() == codemon.getName()) {
            std::cout << "Codemon with name '" << codemon.getName() << "' already exists in pocket." << std::endl;
            return false;
        }
    }
    
    // add the Codemon
    pocket[numCodemons] = codemon;
    numCodemons++;
    
    return true;
}

// Adds an item to the backpack
bool Contestant::addItem(const Item& item) {
    // check if we've reached the maximum number of items
    if (numItems >= 20) {
        std::cout << "Cannot add more items. Maximum limit reached." << std::endl;
        return false;
    }
    
    // add the item
    backpack[numItems] = item;
    numItems++;
    
    return true;
}

// prepare function to update Codemons and items
void Contestant::prepare() {
    std::cout << "\n=== Preparing " << name << " for combat ===" << std::endl;
    char choice;
    
    // updates Codemons
    std::cout << "\nWould you like to add Codemons to your pocket? (y/n): ";
    std::cin >> choice;
    std::cin.ignore();  // cleear newline from input buffer
    
    while ((choice == 'y' || choice == 'Y') && numCodemons < 10) {
        std::string codemonName, codemonType;
        int codemonLevel, codemonHP;
        
        // get Codemon details
        std::cout << "\nEnter Codemon name: ";
        std::getline(std::cin, codemonName);
        
        std::cout << "Enter Codemon type: ";
        std::getline(std::cin, codemonType);
        
        std::cout << "Enter Codemon level: ";
        std::cin >> codemonLevel;
        
        std::cout << "Enter Codemon HP: ";
        std::cin >> codemonHP;
        std::cin.ignore();  // clear newline from input buffer
        
        // ccreate and add the Codemon
        Codemon newCodemon(codemonName, codemonType, codemonLevel, codemonHP);
        
        // update the skills for this Codemon
        char addSkillChoice;
        std::cout << "Would you like to add skills to this Codemon? (y/n): ";
        std::cin >> addSkillChoice;
        std::cin.ignore();  // clears newline from input buffer
        
        while (addSkillChoice == 'y' || addSkillChoice == 'Y') {
            std::string skillName;
            int baseDamage;
            
            // gets skill details
            std::cout << "Enter skill name: ";
            std::getline(std::cin, skillName);
            
            std::cout << "Enter base damage: ";
            std::cin >> baseDamage;
            std::cin.ignore();  // clears newline from input buffer
            
            // creates and add the skill
            Skill newSkill(skillName, baseDamage);
            newCodemon.addSkill(newSkill);
            
            std::cout << "Would you like to add another skill to this Codemon? (y/n): ";
            std::cin >> addSkillChoice;
            std::cin.ignore();  // clears newline from input buffer
        }
        
        // adds the Codemon to the pocket
        if (addCodemon(newCodemon)) {
            std::cout << "Codemon added successfully!" << std::endl;
        }
        
        // checks if user wants to add more Codemons
        if (numCodemons < 10) {
            std::cout << "Would you like to add another Codemon? (y/n): ";
            std::cin >> choice;
            std::cin.ignore();  // Clear newline from input buffer
        } else {
            std::cout << "Pocket is full. Cannot add more Codemons." << std::endl;
            break;
        }
    }
    
    // updates items
    std::cout << "\nWould you like to add items to your backpack? (y/n): ";
    std::cin >> choice;
    std::cin.ignore();  // Clear newline from input buffer
    
    while ((choice == 'y' || choice == 'Y') && numItems < 20) {
        std::string itemName, itemDescription;
        int itemDuration;
        
        // gets item details
        std::cout << "\nEnter item name: ";
        std::getline(std::cin, itemName);
        
        std::cout << "Enter item description: ";
        std::getline(std::cin, itemDescription);
        
        std::cout << "Enter effect duration (in seconds): ";
        std::cin >> itemDuration;
        std::cin.ignore();  // Clear newline from input buffer
        
        // creates and add the item
        Item newItem(itemName, itemDescription, itemDuration);
        
        if (addItem(newItem)) {
            std::cout << "Item added successfully!" << std::endl;
        }
        
        // checks if user wants to add more items
        if (numItems < 20) {
            std::cout << "Would you like to add another item? (y/n): ";
            std::cin >> choice;
            std::cin.ignore();  // clears newline from input buffer
        } else {
            std::cout << "Backpack is full. Cannot add more items." << std::endl;
            break;
        }
    }
}

// prints function
void Contestant::print() const {
    std::cout << "\n===============================================" << std::endl;
    std::cout << "Contestant name: " << name << std::endl;
    std::cout << "Number of Codemons owned: " << numCodemons << std::endl;
    
    // sorts Codemons by level selection sort
    Codemon sortedPocket[10];
    for (int i = 0; i < numCodemons; i++) {
        sortedPocket[i] = pocket[i];
    }
    
    for (int i = 0; i < numCodemons - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < numCodemons; j++) {
            if (sortedPocket[j].getLevel() < sortedPocket[minIndex].getLevel()) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            Codemon temp = sortedPocket[i];
            sortedPocket[i] = sortedPocket[minIndex];
            sortedPocket[minIndex] = temp;
        }
    }
    
    // prints pocket list
    std::cout << "Pocket list (sorted by level):" << std::endl;
    for (int i = 0; i < numCodemons; i++) {
        std::cout << "  " << (i + 1) << ") ";
        sortedPocket[i].print();
    }
    
    // sorts items by duration selection sort
    Item sortedBackpack[20];
    for (int i = 0; i < numItems; i++) {
        sortedBackpack[i] = backpack[i];
    }
    
    for (int i = 0; i < numItems - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < numItems; j++) {
            if (sortedBackpack[j].getDuration() < sortedBackpack[minIndex].getDuration()) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            Item temp = sortedBackpack[i];
            sortedBackpack[i] = sortedBackpack[minIndex];
            sortedBackpack[minIndex] = temp;
        }
    }
    
    // prints backpack list
    std::cout << "Backpack list (sorted by effect duration):" << std::endl;
    for (int i = 0; i < numItems; i++) {
        std::cout << "  " << (i + 1) << ") ";
        sortedBackpack[i].print();
    }
    std::cout << "===============================================" << std::endl;
}

// accessor methods
std::string Contestant::getName() const {
    return name;
}

int Contestant::getNumCodemons() const {
    return numCodemons;
}

const Codemon* Contestant::getPocket() const {
    return pocket;
}
// prints visible map
void Contestant::printVisibleMap() const {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            std::cout << visibleMap[i][j] << ' ';
        }
        std::cout << '\n';
    }
}

// updates visibility on map
void Contestant::revealTile(int x, int y, char terrain) {
    if (x >= 0 && x < 5 && y >= 0 && y < 5) {
        visibleMap[x][y] = terrain;
    }
}