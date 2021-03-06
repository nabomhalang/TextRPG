#include "Enemy.h"

Enemy::Enemy(int level)
{
	this->level = level;
	this->hpMax = rand() % (level * 5) + level * 2;
	this->hp = this->hpMax;
	this->damgeMin = this->level * 1;
	this->damgeMax = this->level * 2;
	this->dropChance = rand() % 100 + 1;
	this->defence = rand() % level*3 + 1;
	this->accuracy = rand() % level*3 + 1;
}

Enemy::~Enemy()
{

}

std::string Enemy::getInformation() const
{
	return "레벨 : " + std::to_string(this->level) + "\n" +
		"hp / hp max : " + std::to_string(this->hp) + " / " + std::to_string(this->hpMax) + "\n" +
		"데미지 : " + std::to_string(this->damgeMin) + " ~ " + std::to_string(this->damgeMax) + "\n" +
		"방어력 : " + std::to_string(this->defence) + "\n" +
		"정확도 : " + std::to_string(this->accuracy) + "\n" +
		"drop : " + std::to_string(this->dropChance) + "%\n";

}

void Enemy::takeDamge(int damge)
{
	this->hp -= damge;
	if (this->hp <= 0)
	{
		this->hp = 0;
	}
}