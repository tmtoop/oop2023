#pragma once

#include "Shape.h"

class Square : public Shape
{
private:
	size_t length;
public:
	void getLabel() const override;
	void print() const override;
	size_t getPerimeter() const override;
	Shape* copy() override;

};

