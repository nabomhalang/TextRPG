#include "Game.h"

int main(void)
{
	srand(time(NULL));

	char choice;

	Game game;
	std::cout << "ó���̽ø� n�� ������ Ű��� ĳ���Ͱ� �����ø� y�� �Է����ּ���" << std::endl;
	std::cout << "ĳ���͸� �ҷ��ñ��? (y/n) ";
	std::cin >> choice;

	switch (choice)
	{
	case 'y':
		game.LoadChacter();
		break;

	case 'n':
		game.initGame();
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