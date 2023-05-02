#pragma once
#include "Employee.h"
#include "TeamLeader.h"
class Manager : public Employee
{
private:
	std::vector<TeamLeader*> leaders;	

public:
	Manager(std::string name, size_t salary);
	size_t cost() const;
};

