#include <iostream>
#include <fstream>

const int MAX_SIZE = 1024;

int main()
{
	std::ifstream file2;

	file2.open("Exc2.txt");

	if (!file2.is_open())
	{
		//handle exc
	}

	char buff[MAX_SIZE];

	while (file2.getline(buff, MAX_SIZE))
	{
		std::cout << buff << '\n';
	}

	file2.close();

	return 0;
}