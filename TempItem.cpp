#include "TempItem.h"
#include <iostream>
#include <random>
using namespace std;

tempHelmet::tempHelmet() {
	std::random_device hel;
	armorClassBonus = (hel() % 5) + 1;
}

tempNoHelmet::tempNoHelmet() {}

tempNoArmor::tempNoArmor() {}

tempNoShield::tempNoShield() {}

tempNoRing::tempNoRing() {}

tempNoBelt::tempNoBelt() {}

tempNoBoots::tempNoBoots() {}

tempNoWeapon::tempNoWeapon() {}

tempArmor::tempArmor() {}

tempShield::tempShield() {}

tempRing::tempRing() {}

tempBelt::tempBelt() {}

tempBoots::tempBoots() {}

tempWeapon::tempWeapon() {}