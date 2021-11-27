#pragma once
#include "Item.h"

class Weapon : public Item
{
private:
	int damageMin;
	int damageMax;

public:
	Weapon();
	Weapon(int level, int rarity);
	Weapon(int damageMin, int damageMax, std::string name, int level,
		int buyValue, int sellValue, int rarity);
	virtual ~Weapon();


	//virtual
	virtual Weapon* clone() const;

	//Functions
	std::string toGetInformation();

	inline int getDamageMin()const { return this->damageMin; }
	inline int getDamageMax()const { return this->damageMax; }

	std::string toStirng()const;
	std::string toStirngSave()const;

	static dArrary<std::string> names;
	static void initNames();
};