#pragma once

#include "CarPart.h"

class Tire : public CarPart
{
	double length;
	double profile;
	size_t diameter;
public:
	virtual void display() const override;
	Tire(std::string name_, std::string manuf_, size_t year_, double len_, double profile_, size_t diam_);
};

