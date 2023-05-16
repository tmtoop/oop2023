#pragma once

#include "CarPart.h"
#include "Piston.h"
#include <vector>

class Engine : public CarPart
{
private:
	size_t horsePower;
	std::vector <Piston> pistons;
public:
	virtual void display() const override;
	Engine(std::string name_, std::string manuf_, size_t year_, size_t hp, const std::vector<Piston>& pistons_);
	void addPiston(Piston piston);
};

