#pragma once
#include "Inventory.h"
#include "Enemy.h"

class Character
{
public:
	Character(std::string name = "None", int distanceTravelled = 0, int gold = 0, int level = 0, int exp = 0, int strength = 0, int vitality = 0, int dexterity = 0, int intelligence = 0, int hp = 0, int mp = 0, int statPoints = 0);
	virtual ~Character();

	//Functions
	void initialize(const std::string name);
	void GetChacterStatus() const;
	void levelUp();
	std::string getAsString() const;
	void updateStats();
	void addStatus(int amount, int value);
	void takeDamges(const int damage);


	//private_Accessors(Ä¸½¶È­)
	inline const std::string& getName() const { return this->name; }
	inline const int& getDIstTravel() const { return this->distanceTravelled; }
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
	inline const int& getLuck() const { return this->luck; }
	inline const int& getStatusPoints() const { return this->statPoints; }
	inline const bool& isAlive() { return this->hp > 0; }
	inline const int& getDmage()const { return this->damageMax + this->damageMin; }
	
	inline void setDistTravelled(const int& distance) { this->distanceTravelled = distance; }
	inline void travel() { this->distanceTravelled++; }
	inline void gainExp(const int& exp) { this->exp += exp; }
	

private:

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
};

