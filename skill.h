#ifndef SKILL_H
#define SKILL_H

#include <string>

class Skill {
private:
    std::string name;
    int baseDamage;

public:
    // default constructor
    Skill();
    
    // parameterized constructor
    Skill(const std::string& name, int baseDamage);
    
    // accessor methods
    std::string getName() const;
    int getBaseDamage() const;
    
    // modifier methods
    void setBaseDamage(int damage);
};

#endif // SKILL_H