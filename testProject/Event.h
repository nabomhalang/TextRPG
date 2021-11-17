#pragma once
#include "Character.h"
#include "Puzzle.h"
#include "dArrary.h"
#include <stdlib.h>
#include <cctype>

class Event
{
private:
	int nrOfEvents;
public:
	Event();
	virtual ~Event();

	void generateEvent(Character& character, dArrary<Enemy>& enemy);
	void enemyEncouter(Character& character, dArrary<Enemy>& enemy);
	//void enemyEncouter(Character& character, std::vector<Enemy>& enemy);
	void quzzleEncouter(Character& character);
};

