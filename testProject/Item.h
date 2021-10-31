#pragma once
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Item
{
private:
	string name;
	int buyvalue;
	int sellvalue;
	int level;
	int rarity;

public:
	Item(string name = "None", int level = 0, int buyValue = 0, int sellValue = 0, int rarity = 0);
	virtual ~Item();

	inline string item_debugPrint() const { return this->name; }
	virtual Item* clone() const = 0;

	//Accessors(Ä¸½¶È­)
	inline const string& getName() const { return this->name; };
	inline const int& getLevel() const { return this->level; };
	inline const int& getRarity() const { return this->rarity; };
	inline const int& getSellName() const { return this->sellvalue; };
	inline const int& getBuyName() const { return this->buyvalue; };
};
