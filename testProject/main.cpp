#include "Game.h"
#include <Windows.h>

int main(void)
{
	system("mode con cols=100 lines=50");

	srand(time(NULL));

	Game game;
	Inventory inventory;

	while (game.getPlaying())
	{
		game.initGame();
		game.mainMenu();
	}

	return 0;
}