#include <iostream>
#include "UtilChars.h"

int main(int argc, char* argv[])
{
	std::cout << argv[0] << "\n";
	if (argv[1] && argv[2])
	{
		if (UtilChars::compareCharArray(argv[1], argv[2]))
		{
			std::cout << "true" << "\n" << argv[1] << "\n" << argv[2];
		}
		else {
			std::cout << "false" << "\n" << argv[1] << "\n" << argv[2];
		}
	}
	std::cout << "\n";
	return 0;
}