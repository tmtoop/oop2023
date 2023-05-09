#pragma once

#include "Shape.h"

class Triangle : public Shape
{
private:
	size_t len1, len2, len3;
public:
	void getLabel() const override;
	void print() const override;
	size_t getPerimeter() const override;
	Shape* copy() override;
};

