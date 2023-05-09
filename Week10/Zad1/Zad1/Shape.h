#pragma once

#include <string>
#include <iostream>

class Shape
{
private:
	std::string label;
public:
	virtual void getLabel() const = 0;
	virtual void print() const = 0;
	virtual size_t getPerimeter() const = 0;
	virtual Shape* copy() = 0;

};

