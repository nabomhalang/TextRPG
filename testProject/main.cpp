#include "Game.h"

using namespace std;

int main(void)
{
	srand(time(NULL));


	Game game;
	game.initGame();

	Inventory inventory;

	while (game.getPlaying())
	{
		game.mainMenu();
	}

	return 0;
}