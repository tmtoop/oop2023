#include "CarPart.h"

size_t CarPart::createdParts()
{
	return cntr;
}

CarPart::CarPart(std::string name_, std::string manuf_, size_t year_)
{
	id = ++cntr;
	name = name_;
	manufacturer = manuf_;
	year = year_;
}

std::string CarPart::getName() const
{
	return name;
}

std::string CarPart::getManuf() const
{
	return manufacturer;
}

size_t CarPart::getYear() const
{
	return year;
}

size_t CarPart::getId() const
{
	return id;
}
