class tempHelmet {
public:
	tempHelmet();
	int getACB() { return armorClassBonus; };
private:
	int armorClassBonus;
};

class tempArmor {
public:
	tempArmor();
private:
};

class tempNoArmor : public tempArmor {
public:
	tempNoArmor();
};

class tempShield {
public: 
	tempShield();
};

class tempNoShield : public tempShield {
public:
	tempNoShield();
};

class tempRing {
public:
	tempRing();
};

class tempNoRing : public tempRing {
public:
	tempNoRing();
};

class tempBelt {
public:
	tempBelt();
};

class tempNoBelt : public tempBelt {
public:
	tempNoBelt();
};

class tempBoots {
public:
	tempBoots();
};

class tempNoBoots : public tempBoots {
public:
	tempNoBoots();
};

enum weapType {MELEE, RANGED};

class tempWeapon {
public:
	tempWeapon();
	weapType getType() { return type; };
	void setType(weapType weap) { type = weap; };
private:
	weapType type;

};

class tempNoWeapon : public tempWeapon {
public:
	tempNoWeapon();
};

class tempNoHelmet : public tempHelmet {
public:
	tempNoHelmet();
};