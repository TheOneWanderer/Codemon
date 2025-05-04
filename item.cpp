#include "item.h"
#include <iostream>

// default constructor
Item::Item() : name("Unnamed"), description("None"), duration(0) {
}

// parameterized constructor
Item::Item(const std::string& name, const std::string& description, int duration) 
    : name(name), description(description), duration(duration) {
}

// accessor methods
std::string Item::getName() const {
    return name;
}

std::string Item::getDescription() const {
    return description;
}

int Item::getDuration() const {
    return duration;
}

// print function
void Item::print() const {
    std::cout << name << " - " << description << " (Duration: " << duration << ")" << std::endl;
}