#include "Item.h"

Item::Item()
{
	this->name = "EMPTY";
	this->level = 0;
	this->buyvalue = 0;
	this->sellvalue = 0;
	this->rarity = -1;
	this->itemType = -1;
}

Item::Item(int itemType, int level, int rarity)
{
	this->name = "None";
	this->level = rand() % (level+2) + 1;
	this->buyvalue = level * this->rarity * 10;
	this->sellvalue = this->buyvalue / 2;
	this->rarity = rarity;
	this->itemType = itemType;
}

Item::Item(int itemType, std::string name, int level, int buyValue, int sellValue, int rarity)
{
	this->name = name;
	this->level = level;
	this->buyvalue = buyValue;
	this->sellvalue = sellValue;
	this->rarity = rarity;
	this->itemType = itemType;
}

Item::~Item()
{

}