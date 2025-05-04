#include "utility.h"
#include <iostream>
#include <string>

// friend function implementation
void skillLookUp(const Contestant contestants[], int size) {
    std::string skillName;
    bool found = false;
    
    std::cout << "\n=== Skill Lookup ===\n" << std::endl;
    std::cout << "Enter the name of the skill to look up: ";
    std::getline(std::cin, skillName);
    
    std::cout << "\nSkill name: " << skillName << std::endl;
    std::cout << "Acquired by: " << std::endl;
    
    // loops through all contestants
    for (int i = 0; i < size; i++) {
        // loops through each Codemon in the contestants pocket
        for (int j = 0; j < contestants[i].numCodemons; j++) {
            const Codemon& codemon = contestants[i].pocket[j];
            const Skill* skills = codemon.getSkills();
            int numSkills = codemon.getNumSkills();
            
            // checks each skill of  Codemon
            for (int k = 0; k < numSkills; k++) {
                if (skills[k].getName() == skillName) {
                    found = true;
                    std::cout << "  - " << codemon.getName() << " (" << contestants[i].getName() 
                              << ") - Base damage: " << skills[k].getBaseDamage() << std::endl;
                }
            }
        }
    }
    
    if (!found) {
        std::cout << "  No Codemons found with this skill." << std::endl;
    }
}