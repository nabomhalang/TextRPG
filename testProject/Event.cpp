#include "Event.h"

Event::Event()
{
	this->nrOfEvents = 2;
}

Event::~Event()
{

}

void Event::generateEvent(Character &character, dArrary<Enemy>& enemy)
{
	int events = rand() % this->nrOfEvents;
	//int events = 1; //test case
	switch (events)
	{
	case 0:
		enemyEncouter(character, enemy);
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

void Event::enemyEncouter(Character& character, dArrary<Enemy>& enemy)
{
	bool giveUp = false, playerDefeated = false, enemyDefeated = false;
	while (!giveUp && !playerDefeated && !enemyDefeated)
	{

	}
}

void Event::quzzleEncouter(Character& character)
{
	system("cls");
	std::cin.ignore();
	bool completed = true;
	int userAnswer = 0;
	int chances = 3;

	std::string filePath = ".//puzzle//" + std::to_string(rand() % 2 + 1) + ".txt";

	//std::cout << filePath << std::endl;
	Puzzle puzzle(filePath);
	

	while (completed && chances >= 1)
	{
		system("cls");
		std::cout << "기회 : " << chances << std::endl;
		std::cout << puzzle.getInformatin() << std::endl;
		

		std::cout << "\n답 : ";
		std::cin >> userAnswer;

		if (std::cin.fail())
		{
			std::cout << "잘못된 입력,.,." << std::endl;
			std::cin.clear();
			std::cin.ignore(100, '\n');
			Sleep(800);
			continue;
		}
		chances--;

		std::cout << std::endl;
		if (puzzle.getCorrectAnswer() == userAnswer)
		{
			int gainExp = (rand() % (chances * character.getLevel() * character.getLuck() + 5));
			completed = false;

			character.gainExp(gainExp);
			std::cout << gainExp << "만큼의 경험치를 얻었습니다" << std::endl;
			Sleep(1000);
		}
		else 
		{
			std::cout << "틀렸습니다...";
			Sleep(800);
		}
	}

	if (!completed)
	{
		std::cout << "정답입니다 !!! \n";
		Sleep(1200);
	}
	else
	{
		std::cout << "실패하였습니다...\n";
		Sleep(1200);
	}
}