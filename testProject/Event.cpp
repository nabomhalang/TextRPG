#include "Event.h"

Event::Event()
{
	this->nrOfEvents = 2;
}

Event::~Event()
{

}

void Event::generateEvent(Character &character)
{
	int events = rand() % this->nrOfEvents;
	//int events = 1; //test case
	switch (events)
	{
	case 0:
		enemyEncouter(character);
		break;

	case 1:
		quzzleEncouter(character);
		break;

	case 2:
		break;

	default:
		break;
	}
}

void Event::enemyEncouter(Character& character)
{
	//while()
}

void Event::quzzleEncouter(Character& character)
{
	system("cls");
	std::cin.ignore();
	bool completed = true;
	int userAnswer = 0;
	int chances = 3;
	Puzzle puzzle(".//puzzle//1.txt");
	

	while (completed && chances > 0)
	{
		
		system("cls");
		chances--;
		std::cout << "��ȸ : " << chances+1 << std::endl;
		std::cout << puzzle.getInformatin() << std::endl;

		std::cout << "\n�� : ";
		std::cin >> userAnswer;
		std::cout << std::endl;
		if (puzzle.getCorrectAnswer() == userAnswer)
		{
			int gainExp = rand() % (chances * character.getLevel() * character.getLuck() );
			completed = false;

			character.gainExp(gainExp);
		}
		else 
		{
			std::cout << "Ʋ�Ƚ��ϴ�...";
			Sleep(800);
		}
	}

	if (!completed)
	{
		std::cout << "�����Դϴ� !!! \n";
		Sleep(1200);
	}
	else
	{
		std::cout << "�����Ͽ����ϴ�...\n";
		Sleep(1200);
	}
}