#pragma once
#include <iostream>
class Animal
{
private:
	char* name;
	size_t len;
	size_t age;

	void erase();
	void copy(const Animal& other);
public:
	Animal(const char* name, size_t age, size_t len);
	~Animal();
	Animal(const Animal& other);
	Animal& operator=(const Animal& rhs);
	void print() const;


	void changeName(const char* newName, size_t len);
};

