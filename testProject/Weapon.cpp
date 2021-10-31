#include "Weapon.h"

Weapon::Weapon(int damageMin, int damageMax, string name, int level, int buyValue, int sellValue, int rarity) 
	:Item(name, level, buyValue, sellValue, rarity)
{
	this->damageMax = damageMax;
	this->damageMin = damageMin;
}

Weapon::~Weapon()
{

}

Weapon* Weapon::clone() const
{
	return new Weapon(*this);
}


string Weapon::toGetInformation()
{
	string info = to_string(this->damageMin) + " ~ " + to_string(this->damageMax);

	return info;
}