#include <iostream>
#include <fstream>

int main()
{
	std::ifstream file1;

	file1.open("Exc1.txt",std::ios::ate);

	if (!file1.is_open())
	{
		//handle exc
	}

	std::cout << file1.tellg();

	file1.close();

	return 0;
}