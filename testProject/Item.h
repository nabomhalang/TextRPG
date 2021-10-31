#pragma once
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Item
{
private:
	string name;
	int buyvalue;
	int sellvalue;

public:
	Item();
	virtual ~Item();

	inline string item_debugPrint() const { return this->name; }

};
