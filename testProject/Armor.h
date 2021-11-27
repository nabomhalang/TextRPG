#pragma once
#include "Item.h"

enum arrmorType { HEAD = 0, CHEST, ARMS, LEGS };

class Armor : public Item
{
private:
	int type;
	std::string typeStr;
	int defence;

public:
	Armor();
	Armor(int level, int rarity);
	Armor(int type, int defence, std::string name, int level,
		int buyValue, int sellValue, int rarity);
	virtual ~Armor();

	//virtual
	virtual Armor* clone() const;
	
	//Functions

	inline int getDefence()const { return this->defence; }
	inline int getType()const { return this->type; }

	std::string toStirng()const;
	std::string toStirngSave()const;

	static dArrary<std::string> names;
	static void initNames();
};