#include "Triangle.h"

void Triangle::getLabel() const
{
	std::cout << "I am a triangle\n";
}

void Triangle::print() const
{
	getLabel();
	std::cout << "My perimeter is: " << getPerimeter() << '\n';
}

size_t Triangle::getPerimeter() const
{
	return len1 + len2 + len3;
}

