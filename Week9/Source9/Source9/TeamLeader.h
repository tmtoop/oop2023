#pragma once
#include "Employee.h"

class TeamLeader : public Employee
{
private:
	std::vector<Employee*> employees;
	std::string teamName;
public:
	TeamLeader(std::string name, size_t salary, std::string teamname);


};

