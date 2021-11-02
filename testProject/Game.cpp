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
			std::cout << this->characters[this->activeCharacter].getLevel() << "랩으로 레벨 업 !! \n\n";
			this->characters[this->activeCharacter].levelUp();
		}


		std::cout << "──────메인 메뉴──────" << std::endl;
		std::cout << "0: 끝내기" << std::endl;
		std::cout << "1: 여행가기" << std::endl;
		std::cout << "2: 쇼핑하기" << std::endl;
		std::cout << "3: 쉬기" << std::endl;
		std::cout << "4: 캐릭터 정보" << std::endl;
		std::cout << "5: 캐릭터 만들기" << std::endl;
		std::cout << "6: 캐릭터 저장하기" << std::endl;
		std::cout << "7: 캐릭터 불러오기" << std::endl;
		std::cout << "────────────────" << std::endl;

		std::cout << "선택 : ";
		std::cin >> choice;

		if (std::cin.fail())
		{
			std::cout << "잘못된 입력,.,." << std::endl;
			std::cin.clear();
			std::cin.ignore(100, '\n');
			Sleep(800);
			continue;
		}
		//std::cin.ignore(100, '\n');

		switch (choice)
		{
		case 0:
			playing = false;
			break;

		case 1:
			Travel();
			break;

		case 4:
			characters[this->activeCharacter].GetChacterStatus();
			break;

		case 5:
			std::cin.ignore();
			this->CreateNewChacter();
			this->SaveChacter();
			break;

		case 6:
			std::cin.ignore();
			this->SaveChacter();
			std::cout << "캐릭터가 저장되었습니다!!" << std::endl;
			Sleep(700);
			break;

		case 7:
			std::cin.ignore();
			this->LoadChacter();
			break;

		default:
			break;
		}
	}
}

void Game::CreateNewChacter()
{
	std::string name = "";

	std::cout << "캐릭터의 이름을 입력해 주세요 : ";
	std::getline(std::cin, name);

	characters.push_back(Character());

	this->activeCharacter = characters.size() - 1;
	characters[this->activeCharacter].initialize(name);
}

void Game::SaveChacter()
{
	std::ofstream outFile(fileName);

	if (outFile.is_open())
	{
		for (size_t i = 0; i < characters.size(); i++)
		{
			outFile << characters[i].getAsString() << "\n";
		}
	}

	outFile.close();
}

void Game::LoadChacter()
{
	std::vector<std::string> players;
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
		for (size_t i = 0; i < characters.size(); i++)
		{
			std::cout << i << std::endl;
		}
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
			std::cout << name << "으로 로그인 되었습니다\n" << std::endl;
			Sleep(800);

			str.clear();
		}
	}
	inFile.close();
	if (this->characters.size() <= 0)
	{
		throw("고장!! 캐릭터가 없습니다!!");
	}
}

void Game::Travel()
{
	Event event;
	this->characters[this->activeCharacter].travel();

	event.generateEvent(this->characters[this->activeCharacter]);
}