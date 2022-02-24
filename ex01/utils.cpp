#include "utils.hpp"
#include <string>
#include <iostream>

void get_field(std::string prompt, std::string &field) {
	while (1)
	{
		std::cout << "Please enter " << prompt << ":" << std::endl;
		std::getline(std::cin, field);
		if (field.length() == 0)
			std::cout << "Empty fields are not allowed." << std::endl;
		else
			break;
	}
}

std::string trunc(std::string str) {
	if (str.size() <= 10)
		return str;
	str = str.substr(0,9).append(".");
	return str;
}
