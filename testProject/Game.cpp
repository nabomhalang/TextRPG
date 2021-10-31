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
	cout << "──────메인 메뉴──────" << endl;
	cout << "0: 끝내기" << endl;
	cout << "1: 여행가기" << endl;
	cout << "2: 쇼핑하기" << endl;
	cout << "3: 레벨업하기" << endl;
	cout << "4: 쉬기" << endl;
	cout << "5: 캐릭터 정보" << endl;
	cout << "6: 캐릭터 만들기" << endl;
	cout << "7: 캐릭터 저장하기" << endl;
	cout << "8: 캐릭터 불러오기" << endl;
	cout << "────────────────" << endl;

	cout << "선택 : ";
	cin >> choice;

	switch (choice)
	{
	case 0:
		playing = false;
		break;

	case 5:
		characters[this->activeCharacter].GetChacterStatus();
		break;

	case 6:
		cin.ignore();
		this->CreateNewChacter();
		this->SaveChacter();
		break;

	case 7:
		cin.ignore();
		this->SaveChacter();
		break;

	case 8:
		cin.ignore();
		this->LoadChacter();
		break;

	default:
		break;
	}
}

void Game::CreateNewChacter()
{
	string name = "";

	cout << "캐릭터의 이름을 입력해 주세요 : ";
	getline(cin, name);

	characters.push_back(Character());

	this->activeCharacter = characters.size() - 1;
	characters[this->activeCharacter].initialize(name);
}

void Game::SaveChacter()
{
	ofstream outFile(fileName);

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