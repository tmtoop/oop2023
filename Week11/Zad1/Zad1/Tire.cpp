#include "Tire.h"

void Tire::display() const
{
	std::cout << "Name: " << getName() << '\n'
		<< "Manufacturer: " << getManuf() << '\n'
		<< "Year: " << getYear() << '\n'
		<< "ID: " << getId() << '\n'
		<< "Length: " << length << '\n'
		<< "Profile: " << profile << '\n'
		<< "Diameter: " << diameter << '\n';
}

Tire::Tire(std::string name_, std::string manuf_, size_t year_, double len_, double profile_, size_t diam_): CarPart(name_, manuf_, year_)
{
	length = len_;
	profile = profile_;
	diameter = diam_;
}
