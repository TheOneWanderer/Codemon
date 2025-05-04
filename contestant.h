#ifndef CONTESTANT_H
#define CONTESTANT_H

#include "codemon.h"
#include "item.h"
#include <string>

class Contestant {
private:
    std::string name;
    Codemon pocket[10];
    int numCodemons;
    Item backpack[20];
    int numItems;
    char visibleMap[5][5];

public:
    // default constructor
    Contestant();
    
    // parameterized constructor
    Contestant(const std::string& name);
    
    // copy constructor
    Contestant(const Contestant& other);
    
    // assignment operator
    Contestant& operator=(const Contestant& other);
    
    // adds a Codemon to the pocket
    bool addCodemon(const Codemon& codemon);
    
    // adds an item to the backpack
    bool addItem(const Item& item);
    
    // prepare function to update Codemons and items
    void prepare();
    
    // prints function
    void print() const;
    
    // accessor methods
    std::string getName() const;
    int getNumCodemons() const;
    const Codemon* getPocket() const;
    
    // prints visible map
    void printVisibleMap() const;
    
    // updates visibility on map
    void revealTile(int x, int y, char terrain);
    
    // makes skillLookUp function a friend
    friend void skillLookUp(const Contestant contestants[], int size);
};

#endif // CONTESTANT_H