// Programmer: Braydon Cook
// Date: May 4, 2025
// File: main.cpp
// Assignment: HW7
// Purpose: Main program to test the Codemon Academy classes in battle

#include "codemon.h"
#include "contestant.h"
#include "item.h"
#include "skill.h"
#include "utility.h"
#include <iostream>

int main() {
  std::cout << "=== Welcome to the Codemon Academy ===" << std::endl;

  // creates contestants using different constructors
  std::cout << "\nCreating first contestant (default constructor):"
            << std::endl;
  Contestant c1;

  std::cout << "\nCreating second contestant (parameterized constructor):"
            << std::endl;
  Contestant c2("Player 2");

  std::cout << "\nCreating third contestant (copy constructor):" << std::endl;
  Contestant c3(c1);

  // creats array of contestants
  Contestant contestants[3] = {
      Contestant(""), // placeholder
      Contestant(""), // placeholder
      Contestant("")  // placeholder
  };

  contestants[0] = c1;
  contestants[1] = c2;
  contestants[2] = c3;

  // prepares each contestant
  for (int i = 0; i < 3; i++) {
    contestants[i].prepare();
  }

  // prints information for each contestant
  std::cout << "\n=== Team Information ===" << std::endl;
  for (int i = 0; i < 3; i++) {
    contestants[i].print();
  }

  // test for the skillLookUp function
  skillLookUp(contestants, 3);

  // test for looking up a non-existent skill
  std::cout << "\nTesting lookup for a non-existent skill:" << std::endl;
  skillLookUp(contestants, 3);

  std::cout << "\n=== End of Program ===" << std::endl;

  return 0;
}