#include "Inventory.h"


Inventory::Inventory()
{
	this->cap = 5;
	this->nrOfItem = 0;
	this->itemArr = new Item * [cap];
	this->initialize();
}

Inventory::~Inventory()
{
	for (size_t i = 0; i < this->nrOfItem; i++)
	{
		delete this->itemArr[i];
	}
	delete[] this->itemArr;
}

Inventory::Inventory(const Inventory& obj)
{
	this->cap = obj.cap;
	this->nrOfItem = obj.nrOfItem;
	this->itemArr = new Item * [this->cap];
	
	for (size_t i = 0; i < nrOfItem; i++)
	{
		this->itemArr[i] = obj.itemArr[i]->clone();
	}
	this->initialize(this->nrOfItem);
}

Item& Inventory::operator[](const int index)
{
	if (index < 0 || index >= this->nrOfItem) throw("Not Work INDEX");
	return *this->itemArr[index];
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

	this->itemArr[this->nrOfItem++] = item.clone();
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
		tempArr[i] = this->itemArr[i];
	}

	delete[] this->itemArr;

	this->itemArr = tempArr;
	this->initialize(this->nrOfItem);
}