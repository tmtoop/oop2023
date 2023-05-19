#pragma once
#include "Animal.h"

class Mamal : public Animal
{
	char* owner;
	void copy(const Mamal& other);
	void erase();
public:
	Mamal(const char* name, int weight, const char* owner);
	Mamal(const Mamal& other);
	~Mamal();
	Mamal& operator=(const Mamal& other);

};

