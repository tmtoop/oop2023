#include "Employee.h"

Employee::Employee(std::string name, size_t salary)
{
	name = name;
	salary = salary;
}

size_t Employee::getSalary() const
{
	return salary;
}
