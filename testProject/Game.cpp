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
	cout << "���������������� �޴�������������" << endl;
	cout << "0: ������" << endl;
	cout << "1: ���డ��" << endl;
	cout << "2: �����ϱ�" << endl;
	cout << "3: �������ϱ�" << endl;
	cout << "4: ����" << endl;
	cout << "��������������������������������" << endl;

	cout << "���� : ";
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