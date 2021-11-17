#include "Game.h"

int main(void)
{
	srand(time(NULL));

	int choice;

	Game game;
	std::cout << "ó���̽ø� 0�� ������ Ű��� ĳ���Ͱ� �����ø� 1�� �Է����ּ���" << std::endl;
	std::cout << "ĳ���͸� �ҷ��ñ��? (0/1) ";
	std::cin >> choice;

	while(std::cin.fail() || choice < 0 || choice > 2)
	{
		std::cin.clear();
		std::cin.ignore(100, '\n');

		std::cout << "ó���̽ø� 0�� ������ Ű��� ĳ���Ͱ� �����ø� 1�� �Է����ּ���" << std::endl;
		std::cout << "ĳ���͸� �ҷ��ñ��? (0/1) ";
		std::cin >> choice;
	}

	switch (choice)
	{
	case 0:
		std::cin.ignore();
		game.CreateNewChacter();
		break;

	case 1:
		std::cin.ignore();
		game.LoadChacter();
		break;

	default:
		break;
	}
	
	Inventory inventory;

	while (game.getPlaying())
	{
		game.mainMenu();
	}

	return 0;
}