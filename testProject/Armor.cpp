#include "Armor.h"

dArrary<std::string> Armor::names;

void Armor::initNames()
{
	Armor::names.push("이상한-방어구");
	Armor::names.push("단단한-방어구");
	Armor::names.push("따뜻한-방어구");
	Armor::names.push("불편한-방어구");
}

Armor::Armor()
	:Item()
{
	this->type = -1;
	this->defence = 0;
}

Armor::Armor(int level, int rarity)
	:Item(ItemType::ARMOR ,level, rarity)
{
	this->defence = rand() % (level * (rarity+1));
	this->defence += (rarity +1) * 5;
	this->type = rand() % 4;

	switch (this->type)
	{
	case arrmorType::HEAD:
		this->typeStr = "머리";
		break;
	case arrmorType::CHEST:
		this->typeStr = "상의";
		break;
	case arrmorType::ARMS:
		this->typeStr = "팔";
		break;
	case arrmorType::LEGS:
		this->typeStr = "하의";
		break;
	default:
		break;
	}

	this->setName(Armor::names[rand() % Armor::names.size()]);

	if (rarity == 3)
		this->defence += level * 5;
	if (rarity == 4)
		this->defence += level * 10;
}

Armor::Armor(int type, int defence, std::string name, int level, int buyValue, int sellValue, int rarity)
	:Item(ItemType::ARMOR, name, level, buyValue, sellValue, rarity)
{
	this->type = type;
	this->defence = defence;
}

Armor::~Armor()
{

}

Armor* Armor::clone() const
{
	return new Armor(*this);
}

std::string Armor::toStirng()const
{
	std::string info = 
		this->getName() + " | 종류: " +
		this->typeStr + " | 레벨: " +
		std::to_string(this->getLevel()) + " | 희귀도: " +
		std::to_string(this->getRarity()) + " | 방어력: " +
		std::to_string(this->defence);

	return info;
}

std::string Armor::toStirngSave()const
{
	std::string str =
		std::to_string(this->getItemType()) + " " +
		this->getName() + "  " +
		std::to_string(this->getLevel()) + " " +
		std::to_string(this->getRarity()) + " " +
		std::to_string(this->getBuyValue()) + " " +
		std::to_string(this->getSellValue()) + " " +
		std::to_string(this->defence) + " " +
		std::to_string(this->type) + " ";

	return str;
}