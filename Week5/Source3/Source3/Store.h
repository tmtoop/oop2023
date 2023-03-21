#ifndef __STORE_INCLUDED__
#define __STORE_INCLUDED__
#include "Shoes.h"
#include <exception>
#include <fstream>

class Store
{
private:
	Shoes* m_Array;
	size_t m_Size;
	size_t m_Capacity;

	void copy(const Store& other);
	void erase();
public:
	Store(size_t capacity);//nullptr?
	~Store();
	Store(const Store& other);
	Store& operator=(const Store& rhs);

	void add(const Shoes& newShoes);
	void sell(const std::string& model);
	void addCapacity(const std::string& type, size_t amount);
	void changeRating(const std::string& type, float rating);
	void eraseModel(const std::string& type);
	void readFromFile(const char* fileName);
	void writeToFile(const char* fileName);



};

#endif // !__STORE_INCLUDED__
