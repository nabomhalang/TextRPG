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
	return "���� : " + std::to_string(this->level) + "\n" +
		"ü�� / ü�� �ִ� : " + std::to_string(this->hp) + " / " + std::to_string(this->hpMax) + "\n" +
		"���ݷ� �ּ� ~ ���ݷ� �ִ� : " + std::to_string(this->damgeMin) + " ~ " + std::to_string(this->damgeMax) + "\n" +
		"���� : " + std::to_string(this->defence) + "\n" +
		"��Ȯ�� : " + std::to_string(this->accuracy) + "\n" +
		"������ ������ Ȯ�� : " + std::to_string(this->dropChance) + "\n";

}