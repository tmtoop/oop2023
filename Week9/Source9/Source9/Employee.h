#pragma once
#include <string>
#include <vector>

class Employee
{
private:
	std::string name;
	size_t salary;
public:
	Employee(std::string name, size_t salary);
	size_t getSalary() const;
	//friend std::ostream& operator<<(std::ostream& os, const Employee& e)
	//{
	//	os << "Name: " << e.name << " Salary "
	//		<< e.salary << '\n';
	//	return os;
	//}

};

