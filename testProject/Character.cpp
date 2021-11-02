#include "Character.h"


Character::Character(std::string name, int distanceTravelled, int gold, int level, int exp, int strength, int vitality, int dexterity, int intelligence, int hp, int mp, int statPoints, int skillPoints)
{
	this->distanceTravelled = distanceTravelled;

	this->name = name;
	this->level = level;
	this->exp = exp;
	this->expNext = 0;

	this->gold = gold;

	this->vitality = vitality;
	this->dexterity = dexterity;
	this->intelligence = intelligence;

	this->hp = hp;
	this->hpMax = 0;
	this->mp = mp;
	this->mpMax = 0;
	this->damageMin = 0;
	this->damageMax = 0;
	this->defence = 0;
	this->accuracy = 0;
	this->luck = 0;

	this->statPoints = statPoints;
	this->skillPoints = skillPoints;

	this->updateStats();

}

Character::~Character()
{

}


//Functions
void Character::initialize(const std::string name)
{
	this->distanceTravelled = 0;

	this->name = name;
	this->level = 1;
	this->exp = 0;
	this->expNext = static_cast<int>((50 / 3) * ((pow(level, 3) - 6 * pow(level, 2) + 17 * level) - 12) + 100); //레벨 필요치 알고리즘
	
	this->gold = 1000;

	this->strength = 5;
	this->vitality = 5;
	this->dexterity = 5;
	this->intelligence = 5;
	
	this->hpMax = (this->vitality * 2) + (this->strength/2);
	this->hp = this->hpMax;
	this->mpMax = this->vitality + (this->strength / 2) + (this->dexterity/3);
	this->mp = this->mpMax;
	this->damageMin = this->strength;
	this->damageMax = this->strength + 2;
	this->defence = this->dexterity + (this->intelligence/2);
	this->accuracy = (this->dexterity / 2);
	this->luck = this->intelligence;

	this->statPoints = 0;
	this->skillPoints = 0;
}

void Character::GetChacterStatus() const
{
	system("cls");
	std::cout << "─────캐릭터 정보──────" << std::endl;
	std::cout << "이름 : " << this->name << std::endl;
	std::cout << "레벨 : " << this->level << std::endl;
	std::cout << "Exp / Next EXP : " << this->exp << " / " << this->expNext << std::endl;
	std::cout << "힘 : " << this->strength << std::endl;
	std::cout << "활력 : " << this->vitality << std::endl;
	std::cout << "손재주 : " << this->dexterity << std::endl;
	std::cout << "지능 : " << this->intelligence << std::endl;
	std::cout << "Hp / Hp Max : " << this->hp << " / " << this->hpMax << std::endl;
	std::cout << "Mp / Mp Max : " << this->mp << " / " << this->mpMax << std::endl;
	std::cout << "데미지 : " << this->damageMin << " ~ " << this->damageMax << std::endl;
	std::cout << "방어력 : " << this->defence << std::endl;
	std::cout << "정확도 : " << this->accuracy << std::endl;
	std::cout << "행운 : " << this->luck << std::endl;
	std::cout << "────────────────" << std::endl;
	std::cout << "계속 하시려면 아무키나 입력해주세요 " << std::endl;
	system("pause > null");

}

void Character::levelUp()
{
	while (this->exp >= this->expNext) 
	{
		this->exp -= this->expNext;
		this->level++;
		this->expNext = static_cast<int>((50 / 3) * ((pow(level, 3) - 6 * pow(level, 2) + 17 * level) - 12) + 100); //레벨 필요치 알고리즘
		this->statPoints++;
		this->skillPoints++;
	}
	
}

std::string Character::getAsString() const
{
	return this->name + " "
		+ std::to_string(this->distanceTravelled) + " "
		+ std::to_string(this->gold) + " "
		+ std::to_string(this->level) + " "
		+ std::to_string(this->exp) + " "
		+ std::to_string(this->strength) + " "
		+ std::to_string(this->vitality) + " "
		+ std::to_string(this->dexterity) + " "
		+ std::to_string(this->intelligence) + " "
		+ std::to_string(this->hp) + " "
		+ std::to_string(this->mp) + " "
		+ std::to_string(this->skillPoints) + " "
		+ std::to_string(this->statPoints);
}

void Character::updateStats()
{
	this->expNext = static_cast<int>((50 / 3) * ((pow(level, 3) - 6 * pow(level, 2) + 17 * level) - 12) + 100); //레벨 필요치 알고리즘

	this->hpMax = (this->vitality * 2) + (this->strength / 2);
	this->hp = this->hpMax;
	this->mp = this->mpMax;
	this->damageMin = this->strength;
	this->damageMax = this->strength + 2;
	this->defence = this->dexterity + (this->intelligence / 2);
	this->accuracy = (this->dexterity / 2);
	this->luck = this->intelligence;

	this->statPoints = 0;
	this->skillPoints = 0;
}