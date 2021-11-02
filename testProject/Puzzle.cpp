#include "Puzzle.h"

Puzzle::Puzzle(std::string filename)
{
	this->correctAnswer = 0;
	std::ifstream inFile(filename);

	int nrOfAns = 0;
	std::string answer = "";
	int correctAns = 0;

	if (inFile.is_open())
	{
		std::getline(inFile, this->question);
		inFile >> nrOfAns;
		inFile.ignore();
		

		for (size_t i = 0; i < nrOfAns; i++)
		{
			std::getline(inFile, answer);
			this->answers.push_back(answer);
		}
		
		inFile >> correctAns;
		this->correctAnswer = correctAns;
		inFile.ignore();
	}
	else {
		throw("Could Now Open Puzzle");
	}


	inFile.close();
}

Puzzle::~Puzzle()
{

}

std::string Puzzle::getInformatin()
{
	std::string answers = "";

	for (size_t i = 0; i < this->answers.size(); i++)
	{
		answers += std::to_string(i) + ": " + this->answers[i] + "\n" ;
	}

	return this->question + "\n" + "\n" +
		answers + "\n";
}
