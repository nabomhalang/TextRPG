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
		break;

	case 7:
		std::cin.ignore();
		this->LoadChacter();
		break;

	default:
		break;
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

}

void Game::Travel()
{
	Event event;
	this->characters[this->activeCharacter].travel();

	event.generateEvent(this->characters[this->activeCharacter]);
}