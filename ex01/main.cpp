#include "PhoneBook.hpp"
#include "utils.hpp"
#include <string>
#include <iostream>

#ifndef DEBUG
#define DEBUG 0
#endif

int main() {
	PhoneBook phonebook;
	std::string input;
	while (1) {
		std::cout << "Please input 'ADD', 'SEARCH' OR 'EXIT'." << std::endl;
		std::getline(std::cin, input);
		if (input == "ADD") {
			phonebook.add_contact();
		}
		else if (input == "SEARCH") {
			phonebook.print();
			while (1) {
				int index;
				std::cout << "Please select a contact index." << std::endl;
				std::getline(std::cin, input);
				char *endptr;
				index = strtol(input.c_str(), &endptr, 10);
				index--;
				if (strlen(endptr) > 0 || !phonebook.index_exists(index)) {
					std::cout << "Invalid index." << std::endl;
					continue ;
				}
				phonebook.print_contact(index);
				break ;
			}
		}
		else if (input == "EXIT") {
			break;
		}
		else {
			if (DEBUG)
				std::cout << "I don't understand " << input << std::endl;
		}
	}
}
