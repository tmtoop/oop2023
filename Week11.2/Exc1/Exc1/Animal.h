#pragma once
#include <cstring>
enum class FoodType { Herbivore, Omnivore, Both };

class Animal
{
private:
	char* name;
	int weight;
	void erase();
	void copy(const Animal& rhs);
public:
	virtual int eat() = 0;
	virtual FoodType getFood() = 0;
	Animal(const char* name_, int weight_);
	Animal(const Animal& other);
	Animal& operator=(const Animal& rhs);
	virtual ~Animal();
};

