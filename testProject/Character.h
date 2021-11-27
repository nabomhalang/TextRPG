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
	std::string getInventoryAsString();
	std::string getInventoryAsStringSave();
	void updateStats();
	void addStatus(int amount, int value);
	void takeDamges(const int damage);
	void addItem(const Item& Item) { this->inventory.addItem(Item); }
	void equipItem(unsigned index);

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
	inline const int& getDmage()const { return rand() % ( this->damageMax + this->weapon.getDamageMax() ) + ( this->damageMin + this->weapon.getDamageMin() ); }
	inline const int& getGold()const { return this->gold; }
	inline const int getInventorySize()const { return this->inventory.size(); }
	inline const int getAddDefence()const { return this->armor_arms.getDefence() + this->armor_body.getDefence() + this->armor_head.getDefence() + this->armor_legs.getDefence(); }

	inline void resetHp() { this->hp = this->hpMax; }
	inline void setDistTravelled(const int& distance) { this->distanceTravelled = distance; }
	inline void travel() { this->distanceTravelled++; }
	inline void gainExp(const int exp) { this->exp += exp; }
	inline void gainGold(const int gold) { this->gold += gold; }
	inline void payGold(const int spend) { this->gold -= spend; }
	inline void setWeapon(Weapon weapon) { this->weapon = weapon; }
	inline void setArmorHead(Armor haed) { this->armor_head = haed; }
	inline void setArmorBody(Armor body) { this->armor_body = body; }
	inline void setArmorArms(Armor arms) { this->armor_arms = arms; }
	inline void setArmorLegs(Armor legs) { this->armor_legs = legs; }

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

