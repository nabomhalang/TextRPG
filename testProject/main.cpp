#include "Game.h"
#include "Functions.h"

using namespace std;

int main(void)
{
	srand(time(NULL));


	Game game;
	game.initGame();

	Inventory inventory;
	inventory.addItem(Item());

	inventory.inv_debugPrint();

	while (game.getPlaying())
	{
		game.mainMenu();
	}

	return 0;
}