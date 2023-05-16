#pragma once

#include <iostream>
#include <string>

class CarPart
{
private:
	std::string name;
	std::string manufacturer;
	size_t year;
	size_t id;
	static size_t cntr;
	static size_t createdParts();
	virtual void display() const = 0;
public:
	CarPart(std::string name_, std::string manuf_, size_t year_);
	std::string getName() const;
	std::string getManuf() const;
	size_t getYear() const;
	size_t getId() const;
	virtual ~CarPart() = default;
};

size_t CarPart::cntr = 0;

