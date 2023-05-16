#include "Engine.h"

void Engine::display() const
{
	std::cout << "Name: " << getName() << '\n'
		<< "Manufacturer: " << getManuf() << '\n'
		<< "Year: " << getYear() << '\n'
		<< "ID: " << getId() << '\n'
		<< "HP: " << horsePower << '\n'
		<< "Pistons: ";
	for (size_t i = 0; i < pistons.size(); ++i)
	{
		pistons[i].display();
		std::cout << '\n';
	}
}

Engine::Engine(std::string name_, std::string manuf_, size_t year_, size_t hp, const std::vector<Piston>& pistons_)
	: CarPart(name_, manuf_, year_)
{
	horsePower = hp;
	pistons = pistons_;
}

void Engine::addPiston(Piston piston)
{
	pistons.push_back(piston);
}
