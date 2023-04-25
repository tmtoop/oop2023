#pragma once
#include <utility>
#include "Set.h"
#include <iostream>

const size_t MAX_SIZE = 100;

template <typename T1, typename T2>
class Dictionary
{
	friend Set;
private:
	Set<std::pair<T1, T2>> dictionary;
	size_t size = 0;
public:
	Dictionary();
	void add(const T1& key, const T2& value);
	void remove(const T1& key);
	const T2 operator[](const T1& key) const;
	bool contains(const T1& key) const;
	size_t size() const;

};

template<typename T1, typename T2>
inline Dictionary<T1, T2>::Dictionary()
{
	dictionary(MAX_SIZE);
}

template<typename T1, typename T2>
inline void Dictionary<T1, T2>::add(const T1& key, const T2& value)
{
	if (contains(key))
	{
		for (size_t i = 0; i < size; ++i)
		{
			if (dictionary.arr[i].first == key)
			{
				dictionary.arr[i].second = value;
				return;
			}
		}
	}
	else
	{
		++size;
		dictionary[size] = std::pair<key, value>;
	}
}

template<typename T1, typename T2>
inline void Dictionary<T1, T2>::remove(const T1& key)
{
	if (false == contains(key))
	{
		throw std::runtime_error("Key doesnt exist!");
	}

	for (size_t i = 0; i < size; ++i)
	{
		if (dictionary.arr[i].first == key)
		{
			std::swap(dictionary.arr[i], dictionary.arr[size - 1]);
			--size;
			return;
		}
	}
}

template<typename T1, typename T2>
inline const T2 Dictionary<T1, T2>::operator[](const T1& key) const
{
	if (false == contains(key))
	{
		throw std::runtime_error("Invalid key");
	}

	for (size_t i = 0; i < size; ++i)
	{
		if (dictionary.arr[i].first == key)
		{
			return dictionary.arr[i].second;
		}
	}
}

template<typename T1, typename T2>
inline bool Dictionary<T1, T2>::contains(const T1& key) const
{
	for (size_t i = 0; i < size; ++i)
	{
		if (dictionary.arr[i].first == key)
		{
			return true;
		}
	}
	return false;
}

template<typename T1, typename T2>
inline size_t Dictionary<T1, T2>::size() const
{
	return size;
}
