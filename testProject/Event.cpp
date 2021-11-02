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
	

	while (completed && chances >= 1)
	{
		system("cls");
		std::cout << "��ȸ : " << chances << std::endl;
		std::cout << puzzle.getInformatin() << std::endl;
		

		std::cout << "\n�� : ";
		std::cin >> userAnswer;

		if (std::cin.fail())
		{
			std::cout << "�߸��� �Է�,.,." << std::endl;
			std::cin.clear();
			std::cin.ignore(100, '\n');
			Sleep(800);
			continue;
		}
		chances--;

		std::cout << std::endl;
		if (puzzle.getCorrectAnswer() == userAnswer)
		{
			int gainExp = (rand() % (chances * character.getLevel() * character.getLuck())) + 5;
			completed = false;

			character.gainExp(gainExp);
			std::cout << gainExp << "��ŭ�� ����ġ�� ������ϴ�" << std::endl;
			Sleep(1000);
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