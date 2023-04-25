#pragma once

template <typename T>
class Set
{
private:
	T* arr;
	size_t size;
	size_t capacity;

	void erase();
	void copy(const Set<T>& other);
	void resize();

public:
	Set(size_t capacity);
	~Set();
	Set(const Set<T>& other);
	Set<T>& operator=(const Set<T>& rhs);

	void add(T& newElem);
	bool isEmpty() const;
	void print() const;
	bool contains(const T& elem) const;

};

template<typename T>
inline void Set<T>::erase()
{
	delete[] arr;
	arr = nullptr;
	size = 0;
	capacity = 0;
}

template<typename T>
inline void Set<T>::copy(const Set<T>& other)
{
	capacity = other.capacity;
	size = other.size;
	if (nullptr == other.arr)
	{
		arr = nullptr;
	}
	else
	{
		arr = new T[capacity];

		for (size_t i = 0; i < size; ++i)
		{
			arr = other.arr[i];
		}
	}
}

template<typename T>
inline void Set<T>::resize()
{
	T* newArr = new T[capacity * 2];

	for (size_t i = 0; i < size; ++i)
	{
		newArr[i] = arr[i];
	}
	capacity = capacity * 2;
	delete[] arr;
	arr = newArr;
}

template<typename T>
inline Set<T>::Set(size_t capacity)
{
	size = 0;
	capacity = capacity;
	arr = new T[capacity];
}

template<typename T>
inline Set<T>::~Set()
{
	erase();
}

template<typename T>
inline Set<T>::Set(const Set<T>& other)
{
	copy(other);
}

template<typename T>
inline Set<T>& Set<T>::operator=(const Set<T>& rhs)
{
	if (this != &rhs)
	{
		erase();
		copy(rhs);
	}
	return *this;
}

template<typename T>
inline void Set<T>::add(T& newElem)
{
	if (contains(newElem))
	{
		return;
	}
	if (size >= capacity - 1)
	{
		resize();
	}

	// i tova moje s dvoichno no me murzi
	for (size_t i = size - 1; i >= 0; --i)
	{
		if (newElem > arr[i])
		{
			arr[i + 1] = newElem;
			break;
		}
		arr[i + 1] = arr[i];
	}
	++size;
}

template<typename T>
inline bool Set<T>::isEmpty() const
{
	return (size == 0);
}

template<typename T>
inline void Set<T>::print() const
{
	for (size_t i = 0; i < size; ++i)
	{
		std::cout << arr[i] << '\n';
	}
}

template<typename T>
inline bool Set<T>::contains(const T& elem) const
{
	// moje s dvoichno ama me murzi da go pisha

	for (size_t i = 0; i < size; ++i)
	{
		if (elem == arr[i])
		{
			return true;
		}
	}

	return false;
}
