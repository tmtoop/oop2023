#include "Animal.h"

void Animal::erase()
{
	delete[] name;
	name = nullptr;
}

void Animal::copy(const Animal& other)
{
	age = other.age;
	len = other.len;
	if (nullptr == other.name)
	{
		name = nullptr;
	}
	else
	{
		name = new char[len];
		for (size_t i = 0; i < len; ++i)
		{
			name[i] = other.name[i];
		}
	}
}

void Animal::print() const
{
	std::cout << "Name: " << name << " , age: " << age;
}

Animal::Animal(const char* name, size_t age, size_t len)
{
	len = len;
	age = age;
	this->name = new char[len];
	
	for (size_t i = 0; i < len; ++i)
	{
		this->name[i] = name[i];
	}
}

Animal::~Animal()
{
	erase();
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

void Animal::changeName(const char* newName, size_t len)
{
	delete[] this->name;
	name = new char[len];

	for (size_t i = 0; i < len; ++i)
	{
		name[i] = newName[i];
	}
	this->len = len;
}
