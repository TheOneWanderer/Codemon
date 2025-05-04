#ifndef CODEMON_H
#define CODEMON_H

#include "skill.h"
#include <string>
#include <iostream>

class Codemon {
private:
    std::string name;
    std::string type; // Fire, Water, Grass, Electric
    int level;
    int hp;
    Skill skills[6];
    int numSkills;
    
    // private function for evolution
    void evolve();

public:
    // default constructor
    Codemon();
    
    // parameterized constructor
    Codemon(const std::string& name, const std::string& type, int level, int hp);
    
    // add a skill to the Codemon
    bool addSkill(const Skill& skill);
    
    // print function
    void print() const;
    
    // accessor methods
    std::string getName() const;
    std::string getType() const;
    int getLevel() const;
    int getHP() const;
    const Skill* getSkills() const;
    int getNumSkills() const;
    
    // HP manipulation
    Codemon& operator-=(int damage);
    
    // output stream operator
    friend std::ostream& operator<<(std::ostream& os, const Codemon& codemon);
};

#endif // CODEMON_H