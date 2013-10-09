#include "Character.h"
#include <iostream>
#include <random>
using namespace std;

Character::Character() {
	level = 1;
	generateAbilities();
	generateHitPoints(0);
	initializeItems();
	generateArmorClass();
	generateAttackBonus();
	generateDamageBonus();
}

Character::Character(int lvl) {
	level = lvl;
	generateAbilities();
	initializeItems();
	generateHitPoints(0);
	generateArmorClass();
//	generateAttackBonus();
	generateDamageBonus();
}

void Character::initializeItems() {	
	unEquipHelmet();
	unEquipArmor();
	unEquipShield();
	unEquipBelt();
	unEquipBoots();
	unEquipRing1();
	unEquipRing2(); 
	unEquipWeapon();

}

void Character::equipHelmet(tempHelmet &helm) {
	helmet = &helm;
}

void Character::equipArmor(tempArmor &arm) {
	armor = &arm;
}

void Character::equipShield(tempShield &shie) {
	shield = &shie;
}

void Character::equipRing1(tempRing &ring) {
	if (&ring == ring2) {
		cout << "This ring is already equipped!" << endl;
	}
	else {
		ring1 = &ring;
	}
}

void Character::equipRing2(tempRing &ring) {
	if (&ring == ring1) {
		cout << "This ring is already equipped" << endl;
	}
	else {
		ring2 = &ring;
	}
}

void Character::equipBelt(tempBelt &bel) {
	belt = &bel;
}

void Character::equipBoots(tempBoots &boo) {
	boots = &boo;
}

void Character::equipWeapon(tempWeapon &weap) {
	weapon = &weap;
}

/*
Character at level 1 starts off with 10 HP as determined by the fighter class hit die.  The die is rolled for each additional level but the 
abilities modifier is only taken into account if the level is 1.
*/
void Character::generateHitPoints(int prevHP) {
	std::random_device d10;
	int HP = 0;
	if (getLevel() == 1) {
		HP = (d10() % 10) + 1;
		HP += getConstitutionMod();
		if (HP < 1)
			HP = 1;
	} else
		HP = prevHP + ((d10() % 10) + 1);
	hitPoints = HP;
}

void Character::generateArmorClass() {
	int AC = 10 + /*tempArmor->getArmorClass() + tempShield->getArmorClass()*/ getDexterityMod();
	armorClass = AC;
}

void Character::generateDamageBonus() {
	int DB = getStrengthMod();
	damageBonus = DB;
}

void Character::generateAttackBonus() {
	int baseAttackBonus = getLevel();
	int AB = 0;
	if (weapon != &noWeapon) {
		if (weapon->getType() == MELEE) {
			AB = baseAttackBonus + getStrengthMod();
		}
		else if (weapon->getType() == RANGED) {
			AB = baseAttackBonus + getDexterityMod();
		}
	}
	attackBonus = AB;
}

/*
Ability generator uses a random number generator to generate a value between 1 and 20 which is then used to generate the modifier for that ability.
*/
void Character::generateAbilities() {

	//sets ability values
	strength = twentySidedRoll();
	dexterity = twentySidedRoll();
	intelligence = twentySidedRoll();
	wisdom = twentySidedRoll();
	constitution = twentySidedRoll();
	charisma = twentySidedRoll();

	//sets ability modifiers
	strengthMod = valueToModifier(getStrength());
	dexterityMod = valueToModifier(getDexterity());
	intelligenceMod = valueToModifier(getIntelligence());
	wisdomMod = valueToModifier(getWisdom());
	constitutionMod = valueToModifier(getConstitution());
	charismaMod = valueToModifier(getCharisma());
	
}

/*
Converts the value determined by the dice roll to a modifier to be applied to the character's ability according to the following chart:
Ability Chart
----------------
Value	Modifier
1	-5
2-3	-4
4-5	-3
6-7	-2
8-9	-1
10-11	0
12-13	+1
14-15	+2
16-17	+3
18-19	+4
20	+5
*/
int Character::valueToModifier(int value) {
	int modifier = -5;

	for (int i = 1; i < value; i += 2) {
		modifier++;
	}

	return modifier;
	
}

int Character::twentySidedRoll() {
	std::random_device dice;
	int roll = dice() % 20 + 1;
	return roll;
}

int main() {

	Character shit;

	cout << "Level: " << shit.getLevel() << endl << endl;

	cout << "Strength: " << shit.getStrength() << endl << "Strength Mod: " << shit.getStrengthMod() << endl << endl;
	cout << "Dexterity: " << shit.getDexterity() << endl << "Dexterity Mod: " << shit.getDexterityMod() << endl << endl;
	cout << "Intellignece: " << shit.getIntelligence() << endl << "Intelligence Mod: " << shit.getIntelligenceMod() << endl << endl;
	cout << "Wisdom: " << shit.getWisdom() << endl << "Wisdom Mod: " << shit.getWisdomMod() << endl << endl;
	cout << "Constitution: " << shit.getConstitution() << endl << "Constitution Mod: " << shit.getConstitutionMod() << endl << endl;
	cout << "Charisma: " << shit.getCharisma() << endl << "Charisma Mod: " << shit.getCharismaMod() << endl << endl;

	cout << "Hit Points: " << shit.getHitPoints() << endl;
	cout << "Armor Class: " << shit.getArmorClass() << endl;
	cout << "Damage Bonus: " << shit.getDamageBonus() << endl;
	cout << "Attack Bonus: " << shit.getAttackBonus() << endl << endl;
	
	system("pause");

	return 0;
}	