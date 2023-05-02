#include "Pet.h"

void Pet::erase()
{
	delete[] ownerName;
	ownerName = nullptr;
}

void Pet::copy(const Pet& other)
{
	ownerLen = other.ownerLen;
	ownerNumber = other.ownerNumber;

	if (other.ownerName == nullptr)
	{
		ownerName = nullptr;
	}
	else
	{
		this->ownerName = new char[ownerLen];

		for (size_t i = 0; i < ownerLen; ++i)
		{
			this->ownerName[i] = other.ownerName[i];
		}
	}
}

Pet::Pet(const char* name, size_t age, size_t len, size_t ownerLen, const char* ownerName)
	: Animal(name, age, len)
{
	ownerLen = ownerLen;
	this->ownerName = new char[ownerLen];

	for (size_t i = 0; i < ownerLen; ++i)
	{
		this->ownerName[i] = ownerName[i];
	}
}

Pet::~Pet()
{
	erase();
}

Pet::Pet(const Pet& other)
	: Animal(other)
{
	copy(other);
}

Pet& Pet::operator=(const Pet& rhs)
{
	if (this != &rhs)
	{
		Animal::operator=(rhs);

		erase();
		copy(rhs);
	}
	return *this;
}

void Pet::changeOwner(const char* newName, size_t newlen, size_t newNum)
{
	erase();
	ownerNumber = newNum;
	ownerLen = newlen;
	ownerName = new char[newlen];

	for (size_t i = 0; i < newlen; ++i)
	{
		ownerName[i] = newName[i];
	}
}

void Pet::print() const
{
	Animal::print();
	std::cout << "\nOwner name: " << ownerName << " number: " << ownerNumber << '\n';
}
