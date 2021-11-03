#include "Game.h"
#include <Windows.h>

Game::Game()
{
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
		system("cls");
		if (this->characters[this->activeCharacter].getExp() >= this->characters[this->activeCharacter].getExpNext())
		{
			std::cout << this->characters[this->activeCharacter].getLevel() << "������ ���� �� !! \n\n";
			this->characters[this->activeCharacter].levelUp();
		}


		std::cout << "���������������� �޴�������������" << std::endl;
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
			std::cout << "������������ĳ���� ����������������" << std::endl;
			std::cout << "1: ĳ���� ����" << std::endl;
			std::cout << "2: ĳ���� �����" << std::endl;
			std::cout << "3: ĳ���� �����ϱ�" << std::endl;
			std::cout << "4: ĳ���� �ҷ�����" << std::endl;
			std::cout << "5: �ڷ� ����" << std::endl;
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

			default:
				break;
			}
			break;

		default:
			break;
		}
	}
}

void Game::CreateNewChacter()
{
	std::string name = "";

	std::cout << "ĳ������ �̸��� �Է��� �ּ��� : ";
	std::getline(std::cin, name);

	characters.push_back(Character(name));

	this->activeCharacter = characters.size() - 1;
	characters[this->activeCharacter].initialize(name);
}

void Game::SaveChacter()
{
	std::ofstream outFile(fileName);

	if (outFile.is_open())
	{
		for (const auto& character : characters)
		{
			outFile << character.getAsString() << "\n";
		}
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
	std::string space = "";
	std::vector<std::string> spaces;
	std::stringstream str;
	std::stringstream read;

	std::ifstream inFile_re(fileName);

HOME:
	system("cls");
	if (inFile_re.is_open())
	{
		while (std::getline(inFile_re, line))
		{
			space = "";
			for (size_t i = 0; i < line.size(); i++)
			{
				if (line[i] == *" ") break;
				space += line[i];
			}
			spaces.push_back(space);

		}
	}
	inFile_re.close();

	int index = 0;
	for (const auto& i : spaces) { std::cout << index++ << ": " << i << std::endl; }

	int input;
	std::cout << "�ڷΰ���: b" << std::endl;
	std::cout << "�Է�: ";
	std::cin >> input;
	if (input == 'b') return;
	else if (std::cin.fail())
	{
		std::cout << "�߸��� �Է�,.,." << std::endl;
		std::cin.clear();
		std::cin.ignore(100, '\n');
		Sleep(800);
		goto HOME;
	}
	else if (input > spaces.size() - 1) goto HOME;
	
	
	if (inFile.is_open())
	{
		int index = 0;
		while (std::getline(inFile, line))
		{
			if (input == index) {
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
				temp.initialize(name);
				this->activeCharacter = characters.size() - 1;
				this->characters.push_back(Character(temp));
				std::cout << name << " Login !!" << std::endl;
				Sleep(1000);
				str.clear();
				break;
			}
			else index++;
		}
	}
	inFile.close();

	
	if (this->characters.size() <= 0)
	{
		throw("����!! ĳ���Ͱ� �����ϴ�!!");
	}
}

void Game::Travel()
{
	Event event;
	this->characters[this->activeCharacter].travel();

	event.generateEvent(this->characters[this->activeCharacter]);
}