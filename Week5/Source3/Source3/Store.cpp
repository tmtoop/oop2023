#include "Store.h"

void Store::copy(const Store& other)
{
	m_Capacity = other.m_Capacity;
	m_Size = other.m_Size;
	if (nullptr == other.m_Array)
	{
		m_Array = nullptr;
	}
	else
	{
		m_Array = new Shoes[m_Capacity];

		for (size_t i = 0; i < m_Capacity; ++i)
		{
			m_Array[i] = other.m_Array[i];
		}
	}
}

void Store::erase()
{
	delete[] m_Array;
	m_Capacity = 0;
	m_Size = 0;
}

Store::Store(size_t capacity)
{
	m_Capacity = capacity;
	m_Size = 0;
	m_Array = new Shoes[capacity];
}

Store::~Store()
{
	erase();
}

Store::Store(const Store& other)
{
	copy(other);
}

Store& Store::operator=(const Store& rhs)
{
	if (this != &rhs)
	{
		erase();
		copy(rhs);
	}
	return *this;
}

void Store::add(const Shoes& newShoes)
{
	if (m_Size == m_Capacity)
	{
		throw std::runtime_error("Capacity reached!");
	}
	
	for (size_t i = 0; i < m_Size; ++i)
	{
		if (m_Array[i].getType() == newShoes.getType())
		{
			throw std::runtime_error("Type already exists!");
		}
	}

	m_Array[m_Size] = newShoes;
	++m_Size;
}

void Store::sell(const std::string& model)
{
	for (size_t i = 0; i < m_Size; ++i)
	{
		if (m_Array[i].getType() == model)
		{
			m_Array[i].decreaseCount();
		}
	}
}

void Store::addCapacity(const std::string& type, size_t amount)
{
	for (size_t i = 0; i < m_Size; ++i)
	{
		if (m_Array[i].getType() == type)
		{
			m_Array[i].changeCount(amount);
			return;
		}
	}

	//throw std::runtime_error("No such model exists");
}

void Store::changeRating(const std::string& type, float rating)
{
	for (size_t i = 0; i < m_Size; ++i)
	{
		if (m_Array[i].getType() == type)
		{
			m_Array[i].setRating(rating);
			return;
		}
	}
	
	// throw std::runtime_error("No such model exists!");
}

void Store::eraseModel(const std::string& type)
{
	for (size_t i = 0; i < m_Size; ++i)
	{
		if (m_Array[i].getType() == type)
		{
			std::swap(m_Array[i], m_Array[m_Size]);
			--m_Size;
			return;
		}
	}

	//throw std::runtime_error("No such model exists");
}

void Store::readFromFile(const char* fileName)
{
	//todo
}

void Store::writeToFile(const char* fileName)
{
	//todo
}
