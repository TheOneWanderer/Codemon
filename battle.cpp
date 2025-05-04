#include "battle.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Battle::Battle(Codemon& attacker, Codemon& defender)
	: attacker(attacker), defender(defender) {}

void Battle::resolveRound() {
	// randomly decides attack order
	bool attackerFirst = rand() % 2 == 0;

	// damage calculation
	float multiplierA = typeChart.getMultiplier(attacker.getType(), defender.getType());
	float multiplierD = typeChart.getMultiplier(defender.getType(), attacker.getType());

	int damageA = 10 * multiplierA; // example skill damage
	int damageD = 10 * multiplierD; // example skill damage

	if (attackerFirst) {
		defender -= damageA;
		if (defender.getHP() > 0) {
			attacker -= damageD;
		}
	} else {
		attacker -= damageD;
		if (attacker.getHP() > 0) {
			defender -= damageA;
		}
	}
}

void Battle::start() {
	while (attacker.getHP() > 0 && defender.getHP() > 0) {
		resolveRound();
	}

	if (attacker.getHP() <= 0) {
		std::cout << attacker.getName() << " has fainted!" << std::endl;
	}
	if (defender.getHP() <= 0) {
		std::cout << defender.getName() << " has fainted!" << std::endl;
	}
}