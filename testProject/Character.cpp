#include "Character.h"


Character::Character()
{
	this->xPos = 0.0;
	this->yPos = 0.0;

	this->name = "";
	this->level = 0;
	this->exp = 0;
	this->expNext = 0;

	this->vitality = 0;
	this->dexterity = 0;
	this->intelligence = 0;

	this->hp = 0;
	this->hpMax = 0;
	this->mp = 0;
	this->mpMax = 0;
	this->damageMin = 0;
	this->damageMax = 0;
	this->defence = 0;
	this->luck = 0;

	this->statPoints = 0;
	this->skillPoints = 0;


}

Character::~Character()
{

}


//Functions
void Character::initialize(const string name)
{
	this->name = name;
	this->level = 1;
	this->exp = 0;
	this->expNext = static_cast<int>((50 / 3) * ((pow(level, 3) - 6 * pow(level, 2) + 17 * level) - 12) + 100); //���� �ʿ�ġ �˰���
	
	this->strength = 5;
	this->vitality = 5;
	this->dexterity = 5;
	this->intelligence = 5;
	
	this->hp = 10;
	this->hpMax = 10;
	this->mp = 10;
	this->mpMax = 10;
	this->damageMin = 2;
	this->damageMax = 4;
	this->defence = 10;
	this->luck = 0;

	this->statPoints = 0;
	this->skillPoints = 0;
}

void Character::GetChacterStatus() const
{
	system("cls");
	cout << "����������ĳ���� ����������������" << endl;
	cout << "�̸� : " << this->name << endl;
	cout << "���� : " << this->level << endl;
	cout << "Exp / Next EXP : " << this->exp << " / " << this->expNext << endl;
	cout << "�� : " << this->strength << endl;
	cout << "Ȱ�� : " << this->vitality << endl;
	cout << "������ : " << this->dexterity << endl;
	cout << "���� : " << this->intelligence << endl;
	cout << "Hp / Hp Max : " << this->hp << " / " << this->hpMax << endl;
	cout << "Mp / Mp Max : " << this->mp << " / " << this->mpMax << endl;
	cout << "���ݷ� : " << this->damageMin << " ~ " << this->damageMax << endl;
	cout << "���� : " << this->defence << endl;
	cout << "��� : " << this->luck << endl;
	cout << "��������������������������������" << endl;
	cout << "��� �Ͻ÷��� �ƹ�Ű�� �Է����ּ��� " << endl;
	system("pause >> null");

}

void Character::levelUp()
{
	while (this->exp >= this->expNext) 
	{
		this->exp -= this->expNext;
		this->level++;
		this->exp = 0;
		this->expNext = static_cast<int>((50 / 3) * ((pow(level, 3) - 6 * pow(level, 2) + 17 * level) - 12) + 100); //���� �ʿ�ġ �˰���
	
		this->statPoints++;
		this->skillPoints++;
	}
	
}

string Character::getAsString() const
{
	return to_string(this->xPos) + " "
		+ to_string(this->yPos) + " "
		+ this->name + " "
		+ to_string(this->level) + " "
		+ to_string(this->exp) + " "
		+ to_string(this->strength) + " "
		+ to_string(this->vitality) + " "
		+ to_string(this->dexterity) + " "
		+ to_string(this->intelligence) + " "
		+ to_string(this->skillPoints) + " "
		+ to_string(this->statPoints);
}