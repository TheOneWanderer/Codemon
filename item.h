#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item {
private:
    std::string name;
    std::string description;
    int duration;  // in seconds

public:
    // default constructor
    Item();
    
    // parameterized constructor
    Item(const std::string& name, const std::string& description, int duration);
    
    // accessor methods
    std::string getName() const;
    std::string getDescription() const;
    int getDuration() const;
    
    // print function
    void print() const;
};

#endif // ITEM_H