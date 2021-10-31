#include "Game.h"

Game::Game()
{
	choice = 0;
	playing = true;
}

Game::~Game()
{

}

//Functions
void Game::mainMenu()
{
	cout << "──────메인 메뉴──────" << endl;
	cout << "0: 끝내기" << endl;
	cout << "1: 여행가기" << endl;
	cout << "2: 쇼핑하기" << endl;
	cout << "3: 레벨업하기" << endl;
	cout << "4: 쉬기" << endl;
	cout << "────────────────" << endl;

	cout << "선택 : ";
	cin >> choice;

	switch (choice)
	{
	case 0:
		playing = false;
		break;
	default:
		break;
	}
}