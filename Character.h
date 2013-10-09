#include "tempItem.h"
#include <iostream>
using namespace std;

class Character {
public:

	//Playing with a previous character
	Character(int level);

	//first time playing as character
	Character();

	//Generates the player's abilities and attributes
	void generateAbilities();
	void generateHitPoints(int prevHP);
	void generateArmorClass();
	void generateAttackBonus();
	void generateDamageBonus();

	/*
	Makes all item pointers point to the none item so functions that rely on bonuses gained from items
	still function properly
	*/
	void initializeItems();

	int getStrength() { return strength; };
	int getDexterity() { return dexterity; };
	int getIntelligence() { return intelligence; };
	int getWisdom() { return wisdom; };
	int getConstitution() { return constitution; };
	int getCharisma() { return charisma; };

	int getStrengthMod() { return strengthMod; };
	int getDexterityMod() { return dexterityMod; };
	int getIntelligenceMod() { return intelligenceMod; };
	int getWisdomMod() { return wisdomMod; };
	int getConstitutionMod() { return constitutionMod; };
	int getCharismaMod() { return charismaMod; };

	int getLevel() { return level; };

	int getHitPoints() { return hitPoints; };
	int getArmorClass() { return armorClass; };
	int getAttackBonus() { return attackBonus; };
	int getDamageBonus() { return damageBonus; };

	//Equiping items
	void equipHelmet(tempHelmet &helm);
	void equipArmor(tempArmor &arm);
	void equipShield(tempShield &shie);
	void equipRing1(tempRing &ring);
	void equipRing2(tempRing &ring);
	void equipBelt(tempBelt &bel);
	void equipBoots(tempBoots &boo);
	void equipWeapon(tempWeapon &weap);

	//unequiping items
	void unEquipHelmet() { helmet = &noHelm; };
	void unEquipArmor() { armor = &noArmor; };
	void unEquipShield() { shield = &noShield; };
	void unEquipRing1() { ring1 = &noRing; };
	void unEquipRing2() { ring2 = &noRing; };
	void unEquipBelt() { belt = &noBelt; };
	void unEquipBoots() { boots = &noBoots; };
	void unEquipWeapon() { weapon = &noWeapon; };

	//Pointer Objects to items
	//To be edited later with actual item class
	tempHelmet *helmet;
	tempArmor *armor;
	tempShield *shield;
	tempRing *ring1;
	tempRing *ring2;
	tempBelt *belt;
	tempBoots *boots;
	tempWeapon *weapon;

	tempNoHelmet noHelm;
	tempNoArmor noArmor;
	tempNoShield noShield;
	tempNoRing noRing;
	tempNoBelt noBelt;
	tempNoBoots noBoots;
	tempNoWeapon noWeapon;

private:

	static int valueToModifier(int value);
	int twentySidedRoll();

	//ability scores
	int strength;
	int dexterity;
	int intelligence;
	int wisdom;
	int constitution;
	int charisma;

	//Ability modifiers
	int strengthMod;
	int dexterityMod;
	int intelligenceMod;
	int wisdomMod;
	int constitutionMod;
	int charismaMod;

	int hitPoints;
	int armorClass;
	int attackBonus;
	int damageBonus;

	int level;
};