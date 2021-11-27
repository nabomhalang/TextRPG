#include "Character.h"


Character::Character(std::string name, int distanceTravelled, int gold, int level, int exp, int strength, int vitality, int dexterity, int intelligence, int hp, int mp, int statPoints)
{
	this->distanceTravelled = distanceTravelled;

	this->name = name;
	this->level = level;
	this->exp = exp;
	this->expNext = 0;

	this->gold = gold;
	
	this->strength = strength;
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
	this->expNext = static_cast<int>((50 / 3) * ((pow(level, 3) - 6 * pow(level, 2) + 17 * level) - 12) + 100); //���� �ʿ�ġ �˰���
	
	this->gold = 1000;

	this->strength = 5;
	this->vitality = 5;
	this->dexterity = 5;
	this->intelligence = 5;
	
	this->hpMax = (this->vitality * 10) + (this->strength) + this->level * 5;
	this->hp = this->hpMax;
	this->mpMax = this->vitality + (this->strength / 2) + (this->dexterity/3);
	this->mp = this->mpMax;
	this->damageMin = this->strength;
	this->damageMax = this->strength + 6;
	this->defence = this->dexterity + (this->intelligence/2);
	this->accuracy = (this->dexterity / 2) + intelligence;
	this->luck = this->intelligence;

	this->statPoints = 0;

	
}

void Character::GetChacterStatus() const
{
	system("cls");
	std::cout << "����������ĳ���� ����������������" << std::endl;
	std::cout << "�̸� : " << this->name << std::endl;
	std::cout << "���� : " << this->level << std::endl;
	std::cout << "Exp / Next EXP : " << this->exp << " / " << this->expNext << std::endl;
	std::cout << "�� : " << this->strength << std::endl;
	std::cout << "Ȱ�� : " << this->vitality << std::endl;
	std::cout << "������ : " << this->dexterity << std::endl;
	std::cout << "���� : " << this->intelligence << std::endl;
	std::cout << "Hp / Hp Max : " << this->hp << " / " << this->hpMax << std::endl;
	std::cout << "Mp / Mp Max : " << this->mp << " / " << this->mpMax << std::endl;
	std::cout << "������ : " << this->damageMin << "( +" << this->weapon.getDamageMin() << " )" << " ~ " << this->damageMax << "( +" << this->weapon.getDamageMax() << " )" << std::endl;
	std::cout << "���� : " << this->defence <<"( +"<< this->getAddDefence() << " )" << std::endl;
	std::cout << "��Ȯ�� : " << this->accuracy << std::endl;
	std::cout << "��� : " << this->luck << std::endl;
	std::cout << "���� ����Ʈ : " << this->statPoints << std::endl << std::endl;

	std::cout << "��� : " << this->gold << std::endl;
	std::cout << "����Ÿ� : " << this->distanceTravelled << std::endl << std::endl;

	std::cout << "���� : " << this->weapon.getName() << " | ���� : " << this->weapon.getLevel() 
		<< " | ������ : " << this->weapon.getDamageMin() << " - " << this->weapon.getDamageMax() << std::endl;
	std::cout << "���� : " << this->armor_head.getName() << " | ���� : " << this->armor_head.getLevel()
		<< " | ���� : " << this->armor_head.getDefence() << std::endl;
	std::cout << "���� : " << this->armor_body.getName() << " | ���� : " << this->armor_body.getLevel()
		<< " | ���� : " << this->armor_body.getDefence() << std::endl;
	std::cout << "���� : " << this->armor_legs.getName() << " | ���� : " << this->armor_legs.getLevel()
		<< " | ���� : " << this->armor_legs.getDefence() << std::endl;
	std::cout << "�尩 : " << this->armor_arms.getName() << " | ���� : " << this->armor_arms.getLevel()
		<< " | ���� : " << this->armor_arms.getDefence() << std::endl;

	std::cout << "��������������������������������" << std::endl;
	system("pause");

}

void Character::levelUp()
{
	while (this->exp >= this->expNext) 
	{
		this->exp -= this->expNext;
		this->level++;
		this->expNext = static_cast<int>((50 / 3) * ((pow(level, 3) - 6 * pow(level, 2) + 17 * level) - 12) + 100); //���� �ʿ�ġ �˰���
		
		this->statPoints++;


		this->updateStats();
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
		+ std::to_string(this->statPoints) + " "
		+ this->weapon.toStirngSave()
		+ this->armor_head.toStirngSave()
		+ this->armor_body.toStirngSave()
		+ this->armor_arms.toStirngSave()
		+ this->armor_legs.toStirngSave();
}

std::string Character::getInventoryAsString() 
{
	std::string inv;

	for (size_t i = 0; i < this->inventory.size(); i++)
	{
		inv += std::to_string(i) + ": " + this->inventory[i].toStirng() + "\n";
	}

	return inv;
}

std::string Character::getInventoryAsStringSave()
{
	std::string inv;

	for (size_t i = 0; i < this->inventory.size(); i++)
	{
		if (this->inventory[i].getItemType() == ItemType::WEAPON)
			inv += this->inventory[i].toStirngSave();
	}

	inv += "\n";
	
	for (size_t i = 0; i < this->inventory.size(); i++)
	{
		if (this->inventory[i].getItemType() == ItemType::ARMOR)
			inv += this->inventory[i].toStirngSave();
	}

	return inv;
}

void Character::addStatus(int amount, int value)
{
	if (this->statPoints < value) { std::cout << "����Ʈ�� �������� �ʽ��ϴ�." << std::endl; system("pause");  }
	else
	{
		switch (amount)
		{
		case 0:
			this->strength += value;
			std::cout << "���� " << value << " ��ŭ �������׽��ϴ�!!!" << std::endl;
			system("pause");
			break;

		case 1:
			this->vitality += value;
			std::cout << "Ȱ���� " << value << " ��ŭ �������׽��ϴ�!!!" << std::endl;
			system("pause");
			break;

		case 2:
			this->dexterity += value;
			std::cout << "��ø���� " << value << " ��ŭ �������׽��ϴ�!!!" << std::endl;
			system("pause");
			break;

		case 3:
			this->intelligence += value;
			std::cout << "������ " << value << " ��ŭ �������׽��ϴ�!!!" << std::endl;
			system("pause");
			break;


		default:
			std::cout << "����Ʈ�� �� �̻� �������� �ʽ��ϴ�" << std::endl;
			system("pause");
			break;
		}

		this->statPoints -= value;

		this->updateStats();
	}
	
}

void Character::updateStats()
{
	this->expNext = static_cast<int>((50 / 3) * ((pow(level, 3) - 6 * pow(level, 2) + 17 * level) - 12) + 100); //���� �ʿ�ġ �˰���

	this->hpMax = (this->vitality * 10) + (this->strength) + this->level*5;
	
	this->mpMax = this->vitality + (this->strength / 2) + (this->dexterity / 3);
	this->mp = this->mpMax;
	this->damageMin = this->strength;
	this->damageMax = this->strength + 6;
	this->defence = this->dexterity + (this->intelligence / 2);
	this->accuracy = (this->dexterity / 2) + intelligence;
	this->luck = this->intelligence;
}

void Character::takeDamges(const int damage)
{
	this->hp -= damage;

	if (this->hp <= 0)
	{
		this->hp = 0;
	}
}

void Character::equipItem(unsigned index)
{
	if (index < 0 || index > this->inventory.size())
	{
		std::cout << "�߸��� �ε��� �����Դϴ�." << std::endl;
	}
	else
	{
		Weapon* w = nullptr;
		w = dynamic_cast<Weapon*>(&this->inventory[index]);

		Armor* a = nullptr;
		a = dynamic_cast<Armor*>(&this->inventory[index]);

		if (w != nullptr)
		{
			if (this->weapon.getRarity() >= 0)
				this->inventory.addItem(this->weapon);
			this->weapon = *w;
			this->inventory.removeItem(index);
		}
		else if (a != nullptr)
		{
			switch (a->getType())
			{
			case arrmorType::HEAD:
				if (this->armor_head.getRarity() >= 0)
					this->inventory.addItem(this->armor_head);
				this->armor_head = *a;
				this->inventory.removeItem(index);
				break;

			case arrmorType::CHEST:
				if (this->armor_body.getRarity() >= 0)
					this->inventory.addItem(this->armor_body);
				this->armor_body = *a;
				this->inventory.removeItem(index);
				break;

			case arrmorType::ARMS:
				if (this->armor_arms.getRarity() >= 0)
					this->inventory.addItem(this->armor_arms);
				this->armor_arms = *a;
				this->inventory.removeItem(index);
				break;

			case arrmorType::LEGS:
				if(this->armor_legs.getRarity() >= 0)
					this->inventory.addItem(this->armor_legs);
				this->armor_legs = *a;
				this->inventory.removeItem(index);
				break;

			default:
				std::cout << "�������� �ʴ� �����Դϴ�..." << std::endl;
				break;
			}
		}
		else
		{
			std::cout << "������ �߻��Ͽ����ϴ�..." << std::endl;
			system("pause");
		}
	}
	
}
