#include "Mamal.h"

void Mamal::erase()
{
	delete[] owner;
}

Mamal::Mamal(const char* name, int weight, const char* owner_)
	: Animal(name, weight)
{
	this->owner = new char[strlen(owner_) + 1];
	size_t len = strlen(owner_);
	for (size_t i = 0; i < len; ++i)
	{
		this->owner[i] = owner_[i];
	}
	this->owner[len] = '\0';
}

Mamal::~Mamal()
{
	erase();
}
