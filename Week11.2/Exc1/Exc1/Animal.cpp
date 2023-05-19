#include "Animal.h"

void Animal::erase()
{
	delete name;
	name = nullptr;
}

void Animal::copy(const Animal& rhs)
{
	weight = rhs.weight;
	if (rhs.name == nullptr)
	{
		this->name = rhs.name;
	}
	else
	{
		this->name = new char[strlen(rhs.name) + 1];

		for (size_t i = 0; i < strlen(rhs.name); ++i)
		{
			name[i] = rhs.name[i];
		}
		name[strlen(rhs.name)] = '\0';
	}
}

Animal::Animal(const char* name_, int weight_)
{
	this->name = new char[strlen(name_) + 1];

	for (size_t i = 0; i < strlen(name_); ++i)
	{
		name[i] = name_[i];
	}
	name[strlen(name_)] = '\0';
}

Animal::Animal(const Animal& other)
{
	copy(other);
}

Animal& Animal::operator=(const Animal& rhs)
{
	if (this != &rhs)
	{
		erase();
		copy(rhs);
	}
	return *this;
}

Animal::~Animal()
{
	erase();
}
