#include "codemon.h"
#include <iostream>
#include <cstdlib>  // for random number generation
#include <ctime>    // for seeding random number generator

// default constructor
Codemon::Codemon() : name("Unnamed"), type("None"), level(0), hp(0), numSkills(0) {
}

// parameterized constructor
Codemon::Codemon(const std::string& name, const std::string& type, int level, int hp) 
    : name(name), type(type), level(level), hp(hp), numSkills(0) {
}

// add a skill to the Codemon
bool Codemon::addSkill(const Skill& skill) {
    // check if we've reached the maximum number of skills
    if (numSkills >= 6) {
        std::cout << "Cannot add more skills. Maximum limit reached." << std::endl;
        return false;
    }
    
    // check for duplicate skill names
    for (int i = 0; i < numSkills; i++) {
        if (skills[i].getName() == skill.getName()) {
            std::cout << "Skill with name '" << skill.getName() << "' already exists for this Codemon." << std::endl;
            return false;
        }
    }
    
    // add the skill
    skills[numSkills] = skill;
    numSkills++;
    
    // try to evolve after adding a new skill
    evolve();
    
    return true;
}

// private function for evolution
void Codemon::evolve() {
    //seed the random number generator if it hasn't been seeded yet
    static bool seeded = false;
    if (!seeded) {
        srand(time(nullptr));
        seeded = true;
    }
    
    // calculate evolution chance
    int baseLuck = rand() % 71;  // random number between 0 and 70 inclusive
    int evolutionChance = baseLuck + (numSkills * 5);
    
    // check if evolution is triggered
    if (evolutionChance >= 60) {
        // increase level
        level++;
        
        // select a random skill to boost
        int skillIndex = rand() % numSkills;
        
        // calculate random boost percentage between 0 and 100
        int boostPercentage = rand() % 101;
        
        // get current damage and calculate new damage
        int currentDamage = skills[skillIndex].getBaseDamage();
        int newDamage = currentDamage + (currentDamage * boostPercentage / 100);
        
        // updatees the skill's damage
        skills[skillIndex].setBaseDamage(newDamage);
        
        // displays evolution message
        std::cout << "*** EVOLUTION TRIGGERED! ***" << std::endl;
        std::cout << name << " has evolved to level " << level << "!" << std::endl;
        std::cout << "Skill '" << skills[skillIndex].getName() << "' damage increased from " 
                  << currentDamage << " to " << newDamage << " (+" << boostPercentage << "%)" << std::endl;
    }
}

// print function
void Codemon::print() const {
    std::cout << name << " (Type: " << type << ", Level: " << level << ", HP: " << hp << ")" << std::endl;
    
    // sort skills by base damage (selection sort)
    Skill sortedSkills[6];
    for (int i = 0; i < numSkills; i++) {
        sortedSkills[i] = skills[i];
    }
    
    for (int i = 0; i < numSkills - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < numSkills; j++) {
            if (sortedSkills[j].getBaseDamage() < sortedSkills[minIndex].getBaseDamage()) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            Skill temp = sortedSkills[i];
            sortedSkills[i] = sortedSkills[minIndex];
            sortedSkills[minIndex] = temp;
        }
    }
    
    // prints skills
    std::cout << "  Skills (sorted by base damage):" << std::endl;
    for (int i = 0; i < numSkills; i++) {
        std::cout << "    - " << sortedSkills[i].getName() << " (Damage: " 
                  << sortedSkills[i].getBaseDamage() << ")" << std::endl;
    }
}

// accessor methods
std::string Codemon::getName() const {
    return name;
}

std::string Codemon::getType() const {
    return type;
}

int Codemon::getLevel() const {
    return level;
}

int Codemon::getHP() const {
    return hp;
}

const Skill* Codemon::getSkills() const {
    return skills;
}

int Codemon::getNumSkills() const {
    return numSkills;
}

// HP manipulation
Codemon& Codemon::operator-=(int damage) {
    hp -= damage;
    if (hp < 0) {
        hp = 0; // HP should not go below 0
    }
    return *this;
}

// otput stream operator
std::ostream& operator<<(std::ostream& os, const Codemon& codemon) {
    os << "Name: " << codemon.name << "\n"
       << "Type: " << codemon.type << "\n"
       << "Level: " << codemon.level << "\n"
       << "HP: " << codemon.hp << "/" << codemon.hp << "\n";
    return os;
}