#ifndef __SHOES_INCLUDED__
#define __SHOES_INCLUDED__
#include <string>
#include <iostream>
class Shoes
{
private:
	std::string m_Manufacturer;
	std::string m_Type;
	double m_Price;
	float m_Rating;
	size_t m_Count;
public:
	std::string getType() const;
	size_t getCount() const;
	void decreaseCount();
	void changeCount(size_t amount);
	void setRating(float rating);
};

#endif // !__SHOES_INCLUDED__
