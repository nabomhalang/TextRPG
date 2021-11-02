#pragma once
#include "Inventory.h"
#include "Enemy.h"

class Character
{
public:
	Character();
	virtual ~Character();

	//Functions
	void initialize(const std::string name);
	void GetChacterStatus() const;
	void levelUp();
	std::string getAsString() const;

	//private_Accessors(Ä¸½¶È­)
	inline const double& getXpos() const { return this->xPos; }
	inline const double& getYpos() const { return this->yPos; }
	inline const std::string& getName() const { return this->name; }
	inline const int& getLevel() const { return this->level; }
	inline const int& getExp() const { return this->exp; }
	inline const int& getExpNext() const { return this->expNext; }
	inline const int& getHp() const { return this->hp; }
	inline const int& getHpMax() const { return this->hpMax; }
	inline const int& getMp() const { return this->mp; }
	inline const int& getMpMax() const { return this->mpMax; }
	inline const int& getDamageMin() const { return this->damageMin; }
	inline const int& getDamageMax() const { return this->damageMax; }
	inline const int& getDefence() const { return this->defence; }
	inline const int& getAccuracy() const { return this->accuracy; }

private:
	double xPos;
	double yPos;

	int distanceTravelled;

	Inventory inventory;
	Weapon weapon;

	Armor armor_head;
	Armor armor_body;
	Armor armor_arms;
	Armor armor_legs;

	int gold;

	std::string name;
	int level;
	int exp;
	int expNext;

	int strength;
	int vitality;
	int dexterity;
	int intelligence;

	int hp;
	int hpMax;
	int mp;
	int mpMax;
	int damageMin;
	int damageMax;
	int defence;
	int accuracy;
	int luck;

	int statPoints;
	int skillPoints;
};

