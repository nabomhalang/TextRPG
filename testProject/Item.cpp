#include "Item.h"

Item::Item(std::string name, int level, int buyValue, int sellValue, int rarity)
{
	this->name = name;
	this->level = level;
	this->buyvalue = buyValue;
	this->sellvalue = sellValue;
	this->rarity = rarity;
}

Item::~Item()
{

}