#include <iostream>
#include "Game.h"
#include "Functions.h"

using namespace std;

int main(void)
{
	srand(time(NULL));

	Game game;
	game.initGame();

	while (game.getPlaying())
	{
		game.mainMenu();
	}

	return 0;
}