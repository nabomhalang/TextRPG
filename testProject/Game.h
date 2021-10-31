#pragma once

#include "Character.h"
#include "Functions.h"
#include <ctime>

class Game
{
public:
	Game();
	virtual ~Game();

	//Function
	void mainMenu();
	void initGame();

	inline bool getPlaying() const { return this->playing; }

private:
	int choice;
	bool playing;

	Character character;
};

