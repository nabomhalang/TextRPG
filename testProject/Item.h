#pragma once
#include <iostream>
#include <string>
#include <iomanip>

class Item
{
private:
	std::string name;
	int buyvalue;
	int sellvalue;
	int level;
	int rarity;

public:
	Item(std::string name = "None", int level = 0, int buyValue = 0, int sellValue = 0, int rarity = 0);
	virtual ~Item();

	inline std::string item_debugPrint() const { return this->name; }
	virtual Item* clone() const = 0;

	//Accessors(Ä¸½¶È­)
	inline const std::string& getName() const { return this->name; };
	inline const int& getLevel() const { return this->level; };
	inline const int& getRarity() const { return this->rarity; };
	inline const int& getSellName() const { return this->sellvalue; };
	inline const int& getBuyName() const { return this->buyvalue; };
};
