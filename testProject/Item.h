#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include "dArrary.h"

enum rarity {COMMON = 0, UNCOMMON, RARE, EPIC, LEGENDARY};
enum ItemType { WEAPON = 0, ARMOR };

class Item
{
private:
	int itemType;
	std::string name;
	int buyvalue;
	int sellvalue;
	int level;
	int rarity;

public:
	Item();
	Item(int itemType, int level, int rarity);
	Item(
		int itemType,
		std::string name, int level,
		int buyValue, int sellValue,
		int rarity);
	virtual ~Item();

	inline std::string item_debugPrint() const { return this->name; }
	
	//virtual
	virtual Item* clone() const = 0;
	virtual std::string toStirng()const = 0;
	virtual std::string toStirngSave()const = 0;

	//Accessors(Ä¸½¶È­)
	inline const std::string& getName() const { return this->name; };
	inline const int& getLevel() const { return this->level; };
	inline const int& getRarity() const { return this->rarity; };
	inline const int& getSellValue() const { return this->sellvalue; };
	inline const int& getBuyValue() const { return this->buyvalue; };
	inline const int& getItemType() const { return this->itemType; }
	inline void setName(std::string name) { this->name = name; }
};
