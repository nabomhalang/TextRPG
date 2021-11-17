#include "Game.h"

int main(void)
{
	srand(time(NULL));

	int choice;

	Game game;
	std::cout << "처음이시면 0를 기존에 키우던 캐릭터가 있으시면 1를 입력해주세요" << std::endl;
	std::cout << "캐릭터를 불러올까요? (0/1) ";
	std::cin >> choice;

	while(std::cin.fail() || choice < 0 || choice > 2)
	{
		std::cin.clear();
		std::cin.ignore(100, '\n');

		std::cout << "처음이시면 0를 기존에 키우던 캐릭터가 있으시면 1를 입력해주세요" << std::endl;
		std::cout << "캐릭터를 불러올까요? (0/1) ";
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