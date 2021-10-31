#include <iostream>
#include "Game.h"
#include "Functions.h"

using namespace std;

int main(void)
{
	srand(time(NULL));

	Game game;
	while (game.getPlaying())
	{
		game.mainMenu();
	}

	return 0;
}