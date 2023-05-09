#include "Circle.h"

void Circle::getLabel() const
{
	std::cout << "I am a circle\n";
}

void Circle::print() const
{
	getLabel();
	std::cout << "My perimeter is " << getPerimeter() << '\n';
}

size_t Circle::getPerimeter() const
{
	return PI * radius * radius;
}
