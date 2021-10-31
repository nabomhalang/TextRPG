#pragma once
#include "Character.h"
#include "Functions.h"
#include <ctime>
#include <vector>
#include <fstream>

class Game
{
public:
	Game();
	virtual ~Game();

	//Function
	void mainMenu();
	void initGame();
	void CreateNewChacter();
	void SaveChacter();
	void LoadChacter();

	inline bool getPlaying() const { return this->playing; }

private:
	int choice;
	bool playing;

	//Character
	int activeCharacter;
	vector<Character> characters;
	string fileName;
};

