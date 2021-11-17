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
			std::cout << "��������������Ʋ �޴���������������������" << std::endl;
			std::cout << "0: Ż���ϱ�" << std::endl;
			std::cout << "1. �����ϱ�" << std::endl;
			std::cout << "2. ����ϱ�" << std::endl;
			std::cout << "3. ������ ����ϱ�" << std::endl;
			std::cout << "������������������������������������������" << std::endl;

			std::cout << "���� : ";
			std::cin >> choice;

			while (std::cin.fail() || choice > 3 || choice < 0)
			{
				system("cls");
				std::cout << "�߸��� �Է�,.,." << std::endl;
				std::cin.clear();
				std::cin.ignore(100, '\n');
				std::cout << "��������������Ʋ �޴���������������������" << std::endl;
				std::cout << "0: Ż���ϱ�" << std::endl;
				std::cout << "1. �����ϱ�" << std::endl;
				std::cout << "2. ����ϱ�" << std::endl;
				std::cout << "3. ������ ����ϱ�" << std::endl;
				std::cout << "������������������������������������������" << std::endl;

				std::cout << "���� : ";
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
				std::cout << "���������������� ���æ�������������������" << std::endl;
				for (size_t i = 0; i < enemy.size(); i++)
				{
					std::cout << i << ": " << "Level : " << enemy[i].getLevel() << "hp : " <<  enemy[i].getHp() << " / " << enemy[i].getMaxhp() << std::endl;
				}
				std::cout << "������������������������������������������" << std::endl;

				std::cout << "���� : ";
				std::cin >> choice;

				while (std::cin.fail() || choice >= enemy.size() || choice < 0)
				{
					system("cls");
					std::cout << "�߸��� �Է�,.,." << std::endl;
					std::cin.clear();
					std::cin.ignore(100, '\n');

					std::cout << "���� : ";
					std::cin >> choice;
				}
				std::cin.ignore(100, '\n');

				attackRoll = (rand() % 100 + 1) + character.getAccuracy();

				//�˰��� ���� �ؾ��� �� ���� �κ�
				if (attackRoll > 50)
				{
					std::cout << "Hit!!" << std::endl;

					damge = character.getDmage();
					enemy[choice].takeDamge(damge);

					std::cout << damge << "��ŭ�� �������� �������ϴ�." << std::endl;

					if (!enemy[choice].inAlive())
					{
						gainExp = enemy[choice].getExp();
						std::cout << "���� �׾����ϴ�!!" << std::endl;
						character.gainExp(gainExp);
						std::cout << gainExp << "��ŭ�� ����ġ�� ������ϴ�!!" << std::endl;
						enemy.remove(choice);
					}
					system("pause");
				}
				else
				{
					std::cout << "���������ϴ�..." << std::endl;
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
			int gainExp = (rand() % (chances * character.getLevel() * character.getLuck() + 5));
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