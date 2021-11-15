#include "Game.h"

int main(void)
{
	srand(time(NULL));

	char choice;

	Game game;
	std::cout << "처음이시면 n를 기존에 키우던 캐릭터가 있으시면 y를 입력해주세요" << std::endl;
	std::cout << "캐릭터를 불러올까요? (y/n) ";
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