#include "Game.h"
#include <Windows.h>

Game::Game()
{
	choice = 0;
	playing = true;

}

Game::~Game()
{

}

//Functions
void Game::initGame()
{
	string name;

	cout << "ĳ������ �̸��� �Է��� �ּ��� : ";
	getline(cin, name);

	character.initialize(name);
}


void Game::mainMenu()
{
	system("cls");
	cout << "���������������� �޴�������������" << endl;
	cout << "0: ������" << endl;
	cout << "1: ���డ��" << endl;
	cout << "2: �����ϱ�" << endl;
	cout << "3: �������ϱ�" << endl;
	cout << "4: ����" << endl;
	cout << "5: ĳ���� ����" << endl;
	cout << "��������������������������������" << endl;

	cout << "���� : ";
	cin >> choice;

	switch (choice)
	{
	case 0:
		playing = false;
		break;

	case 5:
		character.GetChacterStatus();
		break;
	default:
		break;
	}
}