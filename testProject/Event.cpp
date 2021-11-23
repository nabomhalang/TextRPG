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
	//int events = rand() % this->nrOfEvents;
	int events = 0; //test case
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
	int gainGold;
	int random_turn = rand() % 2 + 1;
	int playerTotal = 0;
	int enemyTotal = 0;
	int combatTotal = 0;
	int combatRollPlayer = 0;
	int combatRollEnemy = 0;

	if (random_turn == 1) playerTurn = true;
	else playerTurn = false;

	int nrOfenemy = rand() % 3 + character.getLevel();

	for (size_t i = 0; i < nrOfenemy; i++)
	{
		enemy.push(Enemy(character.getLevel() + rand()%2+1));
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
			std::cout << "���� HP : " << character.getHp() << " / " << character.getHpMax() << std::endl;
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
				std::cout << "���� HP : " << character.getHp() << " / " << character.getHpMax() << std::endl;
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
				std::cout << "���������������� ���æ�������������������������" << std::endl;
				for (size_t i = 0; i < enemy.size(); i++)
				{
					std::cout << i << ": " << 
						" Level : " << enemy[i].getLevel() << 
						" hp : " <<  enemy[i].getHp() << " / " << enemy[i].getMaxhp() << 
						" ����: " << enemy[i].getDefence() <<
						" ��ȭ�� : " << enemy[i].getAccuracy() << std::endl;
				}
				std::cout << "������������������������������������������������" << std::endl;

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
				
				combatTotal = enemy[choice].getDefence() + character.getAccuracy();
				enemyTotal = (enemy[choice].getDefence() / (double)combatTotal) * 100;
				playerTotal = (character.getAccuracy() / (double)combatTotal) * 100;
				combatRollPlayer = rand() % playerTotal + 1;
				combatRollEnemy = rand() % enemyTotal + 1;

				system("cls");
				std::cout << "������������������������ �Ϧ���������������������" << std::endl;
				std::cout << "�÷��̾� �ӵ� : " << combatRollPlayer << std::endl;
				std::cout << "�� �ӵ� : " << combatRollEnemy << std::endl;

				//�˰��� ���� �ؾ��� �� ���� �κ�
				if (combatRollPlayer > combatRollEnemy)
				{
					std::cout << "Hit!!" << std::endl;

					damge = character.getDmage();
					enemy[choice].takeDamge(damge);

					std::cout << damge << "��ŭ�� �������� �������ϴ�." << std::endl;
					std::cout << "���� HP : " << character.getHp() << " / " << character.getHpMax() << std::endl;

					if (!enemy[choice].inAlive())
					{
						gainExp = enemy[choice].getExp();
						gainGold = enemy[choice].getGold();
						std::cout << "���� �׾����ϴ�!!" << std::endl;
						character.gainExp(gainExp);
						character.gainGold(gainGold);
						std::cout << gainExp << "��ŭ�� ����ġ�� ������ϴ�!!" << std::endl;
						std::cout << gainGold << "��ŭ�� ��带 ������ϴ�!!" << std::endl;

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
				system("cls");
				std::cout << "������������������������ �Ϧ���������������������" << std::endl;
				std::cout << "�� : " << i << std::endl << std::endl;

				combatTotal = enemy[i].getDefence() + character.getAccuracy();
				enemyTotal = (enemy[i].getDefence() / (double)combatTotal) * 100;
				playerTotal = (character.getAccuracy() / (double)combatTotal) * 100;
				combatRollPlayer = rand() % playerTotal + 1;
				combatRollEnemy = rand() % enemyTotal + 1;

				std::cout << "\n�÷��̾� �ӵ� : " << combatRollPlayer << std::endl;
				std::cout << "�� �ӵ� : " << combatRollEnemy << std::endl;

				//�˰��� ���� �ؾ��� �� ���� �κ�
				if (combatRollPlayer < combatRollEnemy)
				{
					std::cout << "Hit!!" << std::endl;

					damge = enemy[i].getDamge();
					character.takeDamges(damge);

					std::cout << damge << "��ŭ�� �������� �Ծ����ϴ�..." << std::endl;
					std::cout << "���� HP : " << character.getHp() << " / " << character.getHpMax() << std::endl;

					if (!character.isAlive())
					{
						std::cout << "����� �׾����ϴ�!!" << std::endl;
						playerDefeated = true;
					}
					system("pause");
				}
				else
				{
					std::cout << "���������ϴ�..." << std::endl;
					system("pause");
				}
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