#pragma once
#include "Weapon.h"
#include "Armor.h"

class Inventory
{
private:
	int cap;
	int nrOfItem;
	Item** itemArr;
	void expand();
	void initialize(const int from = 0);

public:
	Inventory();
	virtual ~Inventory();

	Inventory(const Inventory& obj);
	inline int size() const { return this->nrOfItem; }
	Item& operator[](const int index);;

	void addItem(const Item& item);
	void removeItem(int index);

	inline void inv_debugPrint() const
	{
		for (size_t i = 0; i < this->nrOfItem; i++)
		{
			std::cout << this->itemArr[i]->item_debugPrint() << std::endl;
		}
	}
};

