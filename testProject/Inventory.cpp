#include "Inventory.h"


Inventory::Inventory()
{
	this->cap = 10;
	this->nrOfItem = 0;
	this->itemArr = new Item * [cap];
}

Inventory::~Inventory()
{
	for (size_t i = 0; i < this->nrOfItem; i++)
	{
		delete this->itemArr[i];
	}
	delete[] this->itemArr;
}

void Inventory::initialize(const int from)
{
	for (size_t i = from; i < this->cap; i++)
	{
		this->itemArr[i] = nullptr;
	}
}

void Inventory::addItem(const Item& item)
{
	if (this->nrOfItem >= this->cap)
	{
		expand();
	}

	this->itemArr[this->nrOfItem++] = new Item(item);
}

void Inventory::removeItem(int index)
{

}

void Inventory::expand()
{
	this->cap *= 2;

	Item** tempArr = new Item * [this->cap];

	for (size_t i = 0; i < this->nrOfItem; i++)
	{
		tempArr[i] = new Item(*this->itemArr[i]);
	}

	for (size_t i = 0; i < this->nrOfItem; i++)
	{
		delete this->itemArr[i];
	}
	delete[] this->itemArr;

	this->itemArr = tempArr;
	this->initialize(this->nrOfItem);
}