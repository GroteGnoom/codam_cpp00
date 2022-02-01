#include <iostream>
#include <algorithm>

int main(int argc, char **argv)
{
	(void) argv;
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; i < argc; i++)
		{
			/* This could be done simpler with the c-version of toupper, by
			 * not using std:: before toupper, but I figured that wasn't c++
			 * enough. So now I use the c++ version of toupper, but
			 * that one's templated and the compiler doesn't understand which
			 * version it should use for the transform. So now I need to give
			 * the third typename for transform, but I can't skipt the first
			 * two, so I need to fill those in too.*/
			std::transform<char *, char *, int(*)(int)>(
					argv[i], 
					argv[i] + std::strlen(argv[i]),
					argv[i],
					std::toupper);
			std::cout << argv[i];
		}
		std::cout << std::endl;
	}
}
