#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <Windows.h>

class Puzzle
{
private:
	std::string question;
	std::vector<std::string> answers;
	int correctAnswer;

public:
	Puzzle(std::string filename);
	virtual ~Puzzle();
	std::string getInformatin();

	inline const int& getCorrectAnswer()const { return this->correctAnswer; }
};

