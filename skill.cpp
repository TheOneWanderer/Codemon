#include "skill.h"

// default constructor
Skill::Skill() : name("Unnamed"), baseDamage(0) {
}

// parameterized constructor
Skill::Skill(const std::string& name, int baseDamage) : name(name), baseDamage(baseDamage) {
}

// accessor methods
std::string Skill::getName() const {
    return name;
}

int Skill::getBaseDamage() const {
    return baseDamage;
}

// modifier methods
void Skill::setBaseDamage(int damage) {
    baseDamage = damage;
}