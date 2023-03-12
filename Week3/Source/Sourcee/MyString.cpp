#include "MyString.h"
#include <cstring>
#include <exception>
#include <iostream>
void MyString::copy(const MyString& other)
{
	m_Size = other.m_Size;

	if (other.empty())
	{
		m_Arr = nullptr;
	}
	else
	{
		m_Arr = new char[m_Size];
		for (size_t i = 0; i < m_Size; ++i)
		{
			m_Arr[i] = other.m_Arr[i];
		}
	}
}

void MyString::erase()
{
	delete[] m_Arr;
}

MyString::MyString()
{
	m_Arr = nullptr;
	m_Size = 0;
}

MyString::MyString(const char* str)
{
	m_Size = strlen(str);

	if (0 == m_Size)
	{
		m_Arr = nullptr;
	}
	else
	{
		m_Arr = new char[m_Size];
		for (size_t i = 0; i < m_Size; ++i)
		{
			m_Arr[i] = str[i];
		}
	}
}

MyString::MyString(const MyString& other)
{
	copy(other);
}

MyString& MyString::operator=(const MyString& rhs)
{
	if (this != &rhs)
	{
		erase();
		copy(rhs);
	}
	return *this;
}

MyString::~MyString()
{
	erase();
}

int MyString::length() const
{
	return m_Size;
}

char& MyString::at(size_t index)
{
	if (index >= m_Size)
	{
		throw std::exception("Invalid index!");
	}
	return m_Arr[index];
}

int MyString::find(char c, size_t from)
{
	for (size_t i = from; i < m_Size; ++i)
	{
		if (c == m_Arr[i])
		{
			return i;
		}
	}
	return -1;
}

bool MyString::empty() const
{
	return (0 == m_Size);
}

MyString MyString::substr(size_t pos, size_t n)
{
	if (pos >= m_Size)
	{
		throw std::exception("Invalid index!");
	}

	if (0 == n)
	{
		return MyString();
	}

	MyString toReturn;
	if (pos + n > m_Size)
	{
		toReturn.m_Size = m_Size - pos;
	}
	else
	{
		toReturn.m_Size = n;
	}
	toReturn.m_Arr = new char[toReturn.m_Size];
	for (size_t i = pos; i < pos + n && i < m_Size; ++i)
	{
		toReturn.m_Arr[i - pos] = m_Arr[i];
	}

	return toReturn;
}

void MyString::append(const MyString& str)
{
	if (this->empty())
	{
		*this = str;
		return;
	}

	MyString temp;
	temp.m_Size = m_Size + str.m_Size;
	temp.m_Arr = new char[m_Size + str.m_Size];

	for (size_t i = 0; i < m_Size; ++i)
	{
		temp.m_Arr[i] = m_Arr[i];
	}


	for (size_t i = m_Size; i < temp.m_Size; ++i)
	{
		temp.m_Arr[i] = str.m_Arr[i - m_Size];
	}

	//this->erase();
	*this = temp;
}

void MyString::print()
{
	for (size_t i = 0; i < m_Size; ++i)
	{
		std::cout << m_Arr[i];
	}
}
