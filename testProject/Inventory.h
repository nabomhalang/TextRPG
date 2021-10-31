#pragma once
#include "Item.h"

class Inventory
{
private:
	int cap;
	int nrOfItem;
	Item** itemArr;
	void expand();
	void initialize(const int from);

public:
	Inventory();
	virtual ~Inventory();
	void addItem(const Item& item);
	void removeItem(int index);

	inline void inv_debugPrint() const
	{
		for (size_t i = 0; i < this->nrOfItem; i++)
		{
			cout << this->itemArr[i]->item_debugPrint() << endl;
		}
	}
};

