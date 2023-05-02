#pragma once
#include "Animal.h"
class Pet : public Animal
{
private:
	char* ownerName;
	size_t ownerLen;
	size_t ownerNumber;

	void erase();
	void copy(const Pet& other);
public:
	Pet(const char* name, size_t age, size_t len, size_t ownerLen, const char* ownerName);
	~Pet();
	Pet(const Pet& other);
	Pet& operator=(const Pet& rhs);

	void changeOwner(const char* newName, size_t newlen, size_t newNum);
	void print() const;
};

