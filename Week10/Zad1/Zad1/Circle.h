#pragma once

#include "Shape.h"
const float PI = 3.14;

class Circle : public Shape
{
private:
	size_t radius;
public:
	void getLabel() const override;
	void print() const override;
	size_t getPerimeter() const override;
	Shape* copy() override;

};

