#pragma once

template<typename T>
class dArrary
{
private:
	unsigned cap;
	unsigned initialCap;
	unsigned nrOfel;
	T** arr;

	void expand();
	void init(unsigned from);

public:
	dArrary(unsigned size = 5);
	dArrary(const dArrary& obj);
	~dArrary();

	T& operator[] (const unsigned index);
	void operator=(const dArrary& obj);

	unsigned size();
	unsigned maxCap();

	void push(const T ele);
	void remove(unsigned index, bool ordered = false);
};

template<typename T>
dArrary<T>::dArrary(unsigned size)
{
	this->initialCap = size;
	this->cap = size;
	this->nrOfel = 0;

	this->arr = new T * [this->cap];

	this->init(0);
}

template<typename T>
dArrary<T>::dArrary(const dArrary& obj)
{
	this->initialCap = obj.initialCap;
	this->cap = obj.cap;
	this->nrOfel = obj.nrOfel;

	this->arr = new T * [this->cap];

	for (size_t i = 0; i < nrOfel; i++)
	{
		this->arr[i] = new T(*obj.arr[i]);
	}

	this->init(0);
}

template<typename T>
dArrary<T>::~dArrary()
{
	for (size_t i = 0; i < nrOfel; i++)
	{
		delete this->arr[i];
	}
	delete[] arr;
}

template<typename T>
T& dArrary<T>::operator[] (const unsigned index)
{
	if (index < 0 | index >= this->nrOfel)
		throw("잘못된 접근입니다.");

	return *this->arr[index];
}

template<typename T>
void dArrary<T>::operator= (const dArrary& obj)
{
	for (size_t i = 0; i < nrOfel; i++)
	{
		delete this->arr[i];
	}
	delete[] arr;

	this->initialCap = obj.initialCap;
	this->cap = obj.cap;
	this->nrOfel = obj.nrOfel;

	this->arr = new T * [this->cap];

	for (size_t i = 0; i < nrOfel; i++)
	{
		this->arr[i] = new T(*obj.arr[i]);
	}

	this->init(0);
}

template<typename T>
void dArrary<T>::expand()
{
	this->cap *= 2;
	T** tempArr = new T * [this->cap];

	for (size_t i = 0; i < nrOfel; i++)
	{
		tempArr[i] = this->arr[i];
	}
	delete[] arr;

	this->arr = tempArr;

	this->init(this->nrOfel);
}

template<typename T>
void dArrary<T>::init(unsigned from)
{
	for (size_t i = from; i < this->cap; i++)
	{
		this->arr[i] = nullptr;
	}
}

template<typename T>
unsigned dArrary<T>::size()
{
	return this->nrOfel;
}

template<typename T>
unsigned dArrary<T>::maxCap()
{

}

template<typename T>
void dArrary<T>::push(const T ele)
{
	if (this->nrOfel >= this->cap)
	{
		this->expand();
	}

	this->arr[this->nrOfel++] = new T(ele);
}

template<typename T>
void dArrary<T>::remove(unsigned index, bool ordered)
{
	if (index < 0 || index >= this->nrOfel)
		throw("잘못된 접근입니다.");

	if (ordered)
	{
		delete this->arr[index];

		for (size_t i = 0; i < nrOfel-1; i++)
		{
			this->arr[i] = this->arr[i + 1];
		}

		this->arr[--this->nrOfel] = nullptr;
	}
	else
	{
		delete this->arr[index];

		this->arr[index] = this->arr[this->nrOfel - 1];
		this->arr[--this->nrOfel] = nullptr;
	}
}