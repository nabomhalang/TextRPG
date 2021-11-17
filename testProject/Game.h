#pragma once
#include "Event.h"
#include "Functions.h"
#include "dArrary.h"
#include <ctime>
#include <vector>
#include <sstream>

class Game
{
private:
	int choice;
	int amount;
	bool playing;

	//Character
	int activeCharacter;
	std::vector<Character> characters;
	std::string fileName;

	//enemy
	//std::vector<Enemy> enemies;
	dArrary<Enemy> enemies;

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
	void levelupCharacter();
	void selectCharacter();

	inline bool getPlaying() const { return this->playing; }


};

