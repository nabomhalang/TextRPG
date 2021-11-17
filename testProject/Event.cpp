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
	bool playerTurn = false;
	int choice;
	int damge;
	int gainExp;
	int random_turn = rand() % 2 + 1;

	if (random_turn == 1) playerTurn = true;
	else playerTurn = false;

	int nrOfenemy = rand() % 3 + character.getLevel();

	for (size_t i = 0; i < nrOfenemy; i++)
	{
		//enemy.push_back(Enemy(character.getLevel()));
		enemy.push(Enemy(character.getLevel()));
	}

	int attackRoll = 0; int defendRoll = 0;

	bool giveUp = false, playerDefeated = false, enemyDefeated = false;
	while (!giveUp && !playerDefeated && !enemyDefeated)
	{
		if (!character.isAlive()) {
			playerDefeated = true;
		}

		if (enemy.size() <= 0) {
			enemyDefeated = true;
		}

		if (playerTurn && !playerDefeated) 
		{
			
			system("cls");
			std::cout << "──────배틀 메뉴──────────" << std::endl;
			std::cout << "0: 탈출하기" << std::endl;
			std::cout << "1. 공격하기" << std::endl;
			std::cout << "2. 방어하기" << std::endl;
			std::cout << "3. 아이템 사용하기" << std::endl;
			std::cout << "─────────────────────" << std::endl;

			std::cout << "선택 : ";
			std::cin >> choice;

			while (std::cin.fail() || choice > 3 || choice < 0)
			{
				system("cls");
				std::cout << "잘못된 입력,.,." << std::endl;
				std::cin.clear();
				std::cin.ignore(100, '\n');
				std::cout << "──────배틀 메뉴──────────" << std::endl;
				std::cout << "0: 탈출하기" << std::endl;
				std::cout << "1. 공격하기" << std::endl;
				std::cout << "2. 방어하기" << std::endl;
				std::cout << "3. 아이템 사용하기" << std::endl;
				std::cout << "─────────────────────" << std::endl;

				std::cout << "선택 : ";
				std::cin >> choice;
			}
			std::cin.ignore(100, '\n');

			switch (choice)
			{
			case 0:
				giveUp = true;
				system("pause");
				break;
			case 1:

				system("cls");
				std::cout << "───────적 선택──────────" << std::endl;
				for (size_t i = 0; i < enemy.size(); i++)
				{
					std::cout << i << ": " << "Level : " << enemy[i].getLevel() << "hp : " <<  enemy[i].getHp() << " / " << enemy[i].getMaxhp() << std::endl;
				}
				std::cout << "─────────────────────" << std::endl;

				std::cout << "선택 : ";
				std::cin >> choice;

				while (std::cin.fail() || choice >= enemy.size() || choice < 0)
				{
					system("cls");
					std::cout << "잘못된 입력,.,." << std::endl;
					std::cin.clear();
					std::cin.ignore(100, '\n');

					std::cout << "선택 : ";
					std::cin >> choice;
				}
				std::cin.ignore(100, '\n');

				attackRoll = (rand() % 100 + 1) + character.getAccuracy();

				//알고리즘 수정 해야할 것 같은 부분
				if (attackRoll > 50)
				{
					std::cout << "Hit!!" << std::endl;

					damge = character.getDmage();
					enemy[choice].takeDamge(damge);

					std::cout << damge << "만큼의 데미지를 입혔습니다." << std::endl;

					if (!enemy[choice].inAlive())
					{
						gainExp = enemy[choice].getExp();
						std::cout << "적이 죽었습니다!!" << std::endl;
						character.gainExp(gainExp);
						std::cout << gainExp << "만큼의 경험치를 얻었습니다!!" << std::endl;
						enemy.remove(choice);
					}
					system("pause");
				}
				else
				{
					std::cout << "빗나갔습니다..." << std::endl;
					system("pause");
				}

				break;

			case 2:
				break;

			case 3:
				break;

			default:
				break;
			}

			playerTurn = false;
		}
		else if(!playerTurn && !giveUp && !enemyDefeated)
		{
			for (size_t i = 0; i < enemy.size(); i++)
			{

			}

			playerTurn = true;
		}
		
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