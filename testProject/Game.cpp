#include "Game.h"
#include <Windows.h>

Game::Game()
{
	amount = 0;
	choice = 0;
	playing = true;
	activeCharacter = 0;
	fileName = "Caracters.txt";

}

Game::~Game()
{

}

//Functions
void Game::initGame()
{
	this->CreateNewChacter();
}


void Game::mainMenu()
{
	while (this->playing) {
		//this->characters[this->activeCharacter].updateStats();
		system("cls");
		
		if (this->characters[this->activeCharacter].getExp() >= this->characters[this->activeCharacter].getExpNext())
		{
			std::cout << this->characters[this->activeCharacter].getLevel()+1 << "������ ���� �� !! \n\n";
			this->characters[this->activeCharacter].levelUp();
		}
		

		std::cout << "���������������� �޴���������������������" << std::endl;
		std::cout << "�������� ĳ���� = " << this->characters[this->activeCharacter].getName() << " ( " << this->activeCharacter+1 << " / " << this->characters.size() << ") "<< std::endl;
		std::cout << "0: ������" << std::endl;
		std::cout << "1: ���డ��" << std::endl;
		std::cout << "2: �����ϱ�" << std::endl;
		std::cout << "3: ����" << std::endl;
		std::cout << "4: ĳ���� ����" << std::endl;
		std::cout << "������������������������������������������" << std::endl;

		std::cout << "���� : ";
		std::cin >> choice;

		if (std::cin.fail())
		{
			std::cout << "�߸��� �Է�,.,." << std::endl;
			std::cin.clear();
			std::cin.ignore(100, '\n');
			Sleep(800);
			continue;
		}

		switch (choice)
		{
		case 0:
			playing = false;
			break;

		case 1:
			Travel();
			break;

		case 4:
			system("cls");
			std::cout << "������������ĳ���� ������������������������������" << std::endl;
			std::cout << "1: ĳ���� ����" << std::endl;
			std::cout << "2: ĳ���� �����" << std::endl;
			std::cout << "3: ĳ���� �����ϱ�" << std::endl;
			std::cout << "4: ĳ���� �ҷ�����" << std::endl;
			std::cout << "5: ĳ���� �����ϱ�" << std::endl;
			std::cout << "6: ���� ��" << std::endl;
			std::cout << "7: �ڷ� ����" << std::endl;
			std::cout << "������������������������������������������������" << std::endl;

			std::cout << "���� : ";
			std::cin >> choice;

			switch (choice)
			{
			case 1:
				characters[this->activeCharacter].GetChacterStatus();
				break;
			case 2:
				std::cin.ignore();
				this->CreateNewChacter();
				this->SaveChacter();
				break;
			case 3:
				std::cin.ignore();
				this->SaveChacter();
				std::cout << "ĳ���Ͱ� ����Ǿ����ϴ�!!" << std::endl;
				Sleep(700);
				break;
			case 4:
				std::cin.ignore();
				this->LoadChacter();
				break;

			case 5:
				selectCharacter();
				break;

			case 6:
				std::cin.ignore();
				this->levelupCharacter();
				break;

			default:
				break;
			}
			break;

		default:
			break;
		}
	}
}

void Game::levelupCharacter()
{
	this->characters[this->activeCharacter].levelUp();

	if (this->characters[this->activeCharacter].getStatusPoints() > 0)
	{
		std::cout << "����� " << this->characters[this->activeCharacter].getStatusPoints() << " ��ŭ�� ����Ʈ�� ������ �ֽ��ϴ�" << std::endl;
		
		std::cout << "0: ��" << std::endl;
		std::cout << "1: Ȱ��" << std::endl;
		std::cout << "2: ������" << std::endl;
		std::cout << "3: ����" << std::endl;
		
		std::cout << "� �������ͽ��� �ø��� ������? : ";
		std::cin >> choice;
		std::cout << "�� ��ŭ �ø��� �ǰ���? : ";
		std::cin >> amount;

		while (std::cin.fail() || this->choice > 3 || this->characters[this->activeCharacter].getStatusPoints() < this->amount )
		{
			std::cout << "�߸��� �Է�,.,." << std::endl;
			std::cin.clear();
			std::cin.ignore(100, '\n');
			Sleep(800);

			std::cout << "� �������ͽ��� �ø��� ������? : ";
			std::cin >> choice;
			std::cout << "�� ��ŭ �ø��� �ǰ���? : ";
			std::cin >> amount;
		}
		std::cin.ignore(100, '\n');
		std::cout << std::endl;

		switch (this->choice)
		{
		case 0:
			this->characters[this->activeCharacter].addStatus(0, this->amount);
			break;

		case 1:
			this->characters[this->activeCharacter].addStatus(1, this->amount);
			break;

		case 2:
			this->characters[this->activeCharacter].addStatus(2, this->amount);
			break;

		case 3:
			this->characters[this->activeCharacter].addStatus(3, this->amount);
			break;

		default:
			break;
		}
	}
	else
	{
		std::cout << "����Ʈ�� �������� �ʽ��ϴ�." << std::endl;
		system("pause");
	}
	this->characters[this->activeCharacter].updateStats();
}

void Game::CreateNewChacter()
{
	std::string name = "";

	std::cout << "ĳ������ �̸��� �Է��� �ּ��� : ";
	std::getline(std::cin, name);

	for (size_t i = 0; i < this->characters.size(); i++)
	{
		while (name == this->characters[i].getName())
		{
			std::cout << "������ �̸��� ĳ���Ͱ� �����մϴ�!!" << std::endl;

			std::cout << "ĳ������ �̸��� �Է��� �ּ��� : ";
			std::getline(std::cin, name);
		}
	}

	this->characters.push_back(Character(name));

	this->activeCharacter = characters.size() - 1;
	this->characters[this->activeCharacter].initialize(name);
}

void Game::SaveChacter()
{
	std::ofstream outFile(fileName);

	if (outFile.is_open())
		for (const auto& character : characters)
		{
			std::cout << character.getAsString() << std::endl;
			outFile << character.getAsString() << "\n";
			system("pause");
		}
	outFile.close();
}

void Game::LoadChacter()
{
	std::ifstream inFile(fileName);

	this->characters.clear();

	std::string name = "";
	int distanceTravelled = 0;
	int gold = 0;
	int level = 0;
	int exp = 0;
	int strength = 0;
	int vitality = 0;
	int dexterity = 0;
	int intelligence = 0;
	int statPoints = 0;
	int skillPoints = 0;

	int hp = 0;
	int mp = 0;
	int defence = 0;
	int accuracy = 0;
	int luck = 0;
	std::string line = "";
	std::stringstream str;
	
	if (inFile.is_open())
	{
		while (std::getline(inFile, line))
		{
			str.str(line);
			str >> name;
			str >> distanceTravelled;
			str >> gold;
			str >> level;
			str >> exp;
			str >> strength;
			str >> vitality;
			str >> dexterity;
			str >> intelligence;
			str >> hp;
			str >> mp;
			str >> skillPoints;
			str >> statPoints;
			

			Character temp(name, distanceTravelled, gold, level, exp, strength, vitality, dexterity, intelligence, hp, mp, statPoints, skillPoints);
			this->characters.push_back(Character(temp));
			this->activeCharacter = characters.size() - 1;
			this->characters[this->activeCharacter].updateStats();
			std::cout << this->characters[this->activeCharacter].getAsString() << std::endl;
			std::cout << name << " �ҷ����� ����" << std::endl;

			str.clear();
		}
	}
	inFile.close();

	if (this->characters.size() <= 0)
		throw("����!! ĳ���Ͱ� �������� �ʽ��ϴ�.");
	system("pause");
}

void Game::selectCharacter()
{
	system("cls");
	std::cout << "������������ĳ���� ���æ�������������������������" << std::endl;
	for (size_t i = 0; i < this->characters.size(); i++)
	{
		std::cout << i << ": " << this->characters[i].getName() << "(" << this->characters[i].getLevel() << ")" << std::endl;
	}
	std::cout << "������������������������������������������������" << std::endl;
	std::cout << "ĳ���͸� �������ּ��� : ";
	std::cin >> choice;

	while (std::cin.fail() || this->choice < 0 || this->choice >= this->characters.size() )
	{
		std::cout << "�߸��� �Է�,.,." << std::endl;
		std::cin.clear();
		std::cin.ignore(100, '\n');

		std::cout << "ĳ���͸� �������ּ��� : ";
		std::cin >> choice;
	}
	std::cin.ignore(100, '\n');

	this->activeCharacter = this->choice;
	std::cout << this->characters[this->activeCharacter].getName() << "�� ���õǾ����ϴ�." << std::endl;
	this->characters[this->activeCharacter].updateStats();
}

void Game::Travel()
{
	Event event;
	this->characters[this->activeCharacter].travel();

	event.generateEvent(this->characters[this->activeCharacter], this->enemies);
}

