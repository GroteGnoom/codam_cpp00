#include <iostream>

int main(int argc, char **argv)
{
	(void) argv;
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; i < argc; i++)
		{
			std::string str = argv[i];
			for (std::basic_string<char>::size_type j = 0; j < str.size(); j++)
			{
				std::cout << (char)std::toupper(str[j]);
			}
		}
		std::cout << std::endl;
	}
}
