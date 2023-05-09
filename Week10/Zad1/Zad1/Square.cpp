#include "Square.h"

void Square::getLabel() const
{
	std::cout << "I am a square\n";
}

void Square::print() const
{
	getLabel();
	std::cout << "My perimeter is " << getPerimeter() << '\n';
}

size_t Square::getPerimeter() const
{
	return length * 4;
}
