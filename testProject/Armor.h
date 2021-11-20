#pragma once
#include "Item.h"

enum arrmorType { HEAD = 0, CHEST, ARMS, LEGS };

class Armor : public Item
{
private:
	int type;
	int defence;

public:
	Armor(int type = 0, int defence = 0, std::string name = "None", int level = 0,
		int buyValue = 0, int sellValue = 0, int rarity = 0);
	virtual ~Armor();

	//virtual
	virtual Armor* clone() const;

	//Functions
	std::string toGetInformation();

	inline int getDefence()const { return this->defence; }
	inline int getType()const { return this->type; }

};

