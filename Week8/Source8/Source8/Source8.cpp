#include <iostream>
#include "Set.h"

template <typename T>
void Swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

template <typename T>
Set<T> operator+(const Set<T>& fst, const Set<T>& scd)
{
	Set<T> newSet((fst.size + scd.size) * 2);

	for (size_t i = 0; i < fst.size; ++i)
	{
		newSet.add(arr[i]);
	}

	for (size_t i = 0; i < scd.size; ++i)
	{
		newSet.add(arr[i]);
	}

	return newSet;
}

template <typename T>
bool operator<(const Set<T>& fst, const Set<T>& scd)
{
	for (size_t i = 0; i < fst.size; ++i)
	{
		if (false == scd.contains(fst.arr[i]))
		{
			return false;
		}
	}
	return true;
}

int main()
{



	return 0;
}