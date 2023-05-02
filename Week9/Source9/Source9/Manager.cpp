#include "Manager.h"

Manager::Manager(std::string name, size_t salary)
	: Employee(name, salary)
{
}

size_t Manager::cost() const
{
	size_t answ = 0;
	for (size_t i = 0; i < leaders.size(); ++i)
	{
		answ += leaders.at(i)->getSalary();
	}
	return answ;
}
