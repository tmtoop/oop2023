#pragma once

#include "CarPart.h"

class Piston : public CarPart
{
private:
	double diameter;
	double hod;
public:
	virtual void display() const override;

	Piston(std::string name_, std::string manuf_, size_t year_, double diam_, double hod_);
};

