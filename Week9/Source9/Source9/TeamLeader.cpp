#include "TeamLeader.h"

TeamLeader::TeamLeader(std::string name, size_t salary, std::string teamname)
	: Employee(name, salary)
	{
		teamName = teamname;
		std::vector<Employee*> e;
		employees = e;
	}
