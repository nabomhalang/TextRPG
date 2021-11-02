#include "Enemy.h"

Enemy::Enemy(int level)
{
	this->level = level;
	this->hpMax = level * 10;
	this->hp = this->hpMax;
	this->defence = this->level * 4;
	this->damgeMin = this->level * 3;
	this->damgeMax = this->level * 5;
	this->dropChance = rand() % 100;
	this->accuracy = rand() % 100;
}

Enemy::~Enemy()
{

}

std::string Enemy::getInformation() const
{
	return "레벨 : " + std::to_string(this->level) + "\n" +
		"체력 / 체력 최대 : " + std::to_string(this->hp) + " / " + std::to_string(this->hpMax) + "\n" +
		"공격력 최소 ~ 공격력 최대 : " + std::to_string(this->damgeMin) + " ~ " + std::to_string(this->damgeMax) + "\n" +
		"방어력 : " + std::to_string(this->defence) + "\n" +
		"정확도 : " + std::to_string(this->accuracy) + "\n" +
		"아이템 떨구는 확률 : " + std::to_string(this->dropChance) + "\n";

}