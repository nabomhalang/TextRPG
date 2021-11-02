#pragma once
#include "Event.h"
#include "Functions.h"

#include <ctime>
#include <vector>

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
	void Travel();

	inline bool getPlaying() const { return this->playing; }

private:
	int choice;
	bool playing;

	//Character
	int activeCharacter;
	std::vector<Character> characters;
	std::string fileName;
};

