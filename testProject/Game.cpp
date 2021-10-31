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
	cout << "���������������� �޴�������������" << endl;
	cout << "0: ������" << endl;
	cout << "1: ���డ��" << endl;
	cout << "2: �����ϱ�" << endl;
	cout << "3: �������ϱ�" << endl;
	cout << "4: ����" << endl;
	cout << "5: ĳ���� ����" << endl;
	cout << "6: ĳ���� �����" << endl;
	cout << "7: ĳ���� �����ϱ�" << endl;
	cout << "8: ĳ���� �ҷ�����" << endl;
	cout << "��������������������������������" << endl;

	cout << "���� : ";
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

	cout << "ĳ������ �̸��� �Է��� �ּ��� : ";
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