#include "Game.h"
#include <Windows.h>

int main(void)
{
	system("mode con cols=100 lines=50");

	srand(time(NULL));
	Game game;
	std::ifstream characters;
	
	characters.open(game.getFilename());

	if (characters.is_open())
		game.LoadChacter();
	else
	{
		game.CreateNewChacter();
		game.SaveChacter();
	}
	characters.close();
	

	Inventory inventory;

	while (game.getPlaying())
	{
		game.mainMenu();
	}

	return 0;
}