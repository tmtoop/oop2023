#include "Piston.h"

void Piston::display() const
{
	std::cout << "Name: " << getName() << '\n'
		<< "Manufacturer: " << getManuf() << '\n'
		<< "Year: " << getYear() << '\n'
		<< "ID: " << getId() << '\n'
		<< "Diameter: " << diameter << '\n'
		<< "Hod: " << hod << '\n';
}

Piston::Piston(std::string name_, std::string manuf_, size_t year_, double diam_, double hod_)
	: CarPart(name_, manuf_, year_)
{
	diameter = diam_;
	hod = hod_;
}
