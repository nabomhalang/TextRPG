#pragma once
#include "Character.h"
#include "Puzzle.h"
#include <stdlib.h>
#include <cctype>

class Event
{
private:
	int nrOfEvents;
public:
	Event();
	virtual ~Event();

	void generateEvent(Character &character);
	void enemyEncouter(Character& character);
	void quzzleEncouter(Character& character);
};

