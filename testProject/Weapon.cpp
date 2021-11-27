#include "Weapon.h"

dArrary<std::string> Weapon::names;

void Weapon::initNames()
{
	Weapon::names.push("Àå¹ÌÄ®");
	Weapon::names.push("Àß¸°Ä®");
	Weapon::names.push("³ì½¼Ä®");
	Weapon::names.push("±äÄ®");
	Weapon::names.push("ÂªÀºÄ®");
	Weapon::names.push("ÀÏ¹ÝÄ®");
}

Weapon::Weapon()
	:Item()
{
	this->damageMax = 0;
	this->damageMin = 0;
}

Weapon::Weapon(int level, int rarity)
	:Item(ItemType::WEAPON, level, rarity)
{
	this->damageMax = rand() % level * (rarity + 1);
	this->damageMax += (rarity+1) * 5;
	this->setName(Weapon::names[rand() % Weapon::names.size()]);

	if (rarity == 3)
	{
		this->damageMax += level * 5;
	}
	if (rarity == 4)
	{
		this->damageMax += level * 10;
	}


	this->damageMin = this->damageMax / 2;
}

std::string Weapon::toStirng()const
{
	std::string str =
		this->getName() + " | ·¹º§: " +
		std::to_string(this->getLevel()) + " | Èñ±Íµµ: " +
		std::to_string(this->getRarity()) +	" | µ¥¹ÌÁö: " + 
		std::to_string(this->damageMin) + " - " + std::to_string(this->damageMax) + " ";

	return str;
}

Weapon::Weapon(int damageMin, int damageMax, std::string name, int level, int buyValue, int sellValue, int rarity)
	:Item(ItemType::WEAPON, name, level, buyValue, sellValue, rarity)
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


std::string Weapon::toGetInformation()
{
	std::string info = std::to_string(this->damageMin) + " ~ " + std::to_string(this->damageMax);

	return info;
}

std::string Weapon::toStirngSave()const
{
	std::string str =
		std::to_string(this->getItemType()) + " " +
		this->getName() + "  " +
		std::to_string(this->getLevel()) + " " +
		std::to_string(this->getRarity()) + " " +
		std::to_string(this->getBuyValue()) + " " +
		std::to_string(this->getSellValue()) + " " +
		std::to_string(this->damageMin) + " " +
		std::to_string(this->damageMax) + " ";

	return str;
}