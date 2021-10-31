#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include "Functions.h"

using namespace std;

class Game
{
public:
	Game();
	virtual ~Game();

	//Function
	void mainMenu();

	inline bool getPlaying() const { return this->playing; }

private:
	int choice;
	bool playing;
};

