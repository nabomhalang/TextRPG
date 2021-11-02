#pragma once
#include <stdlib.h>
#include <string>

class Enemy
{
private:
	int hp;
	int hpMax;
	int level;
	int damgeMin;
	int damgeMax;
	float dropChance;
	int defence;
	int accuracy;

public:
	Enemy(int level = 0 );
	virtual ~Enemy();

	inline bool inAlive() { return this->hp > 0; }
	std::string getInformation() const;
	inline void takeDamge(int damge) { this->hp -= damge; }
	inline int getDamge()const { return rand() % this->damgeMin - damgeMax; }
	inline int getExp()const { return this->level * 100; }
};

