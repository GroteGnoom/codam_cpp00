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

	while (std::cin) {
		std::cout << "Please input 'ADD', 'SEARCH' OR 'EXIT'." << std::endl;
		std::getline(std::cin, input);
		if (!std::cin)
			break;
		if (input == "ADD") {
			phonebook.add_contact();
		}
		else if (input == "SEARCH") {
			if (!phonebook.index_exists(0)) {
				std::cout << "No contacts found." << std::endl;
				continue;
			}
			phonebook.print();
			while (std::cin) {
				int index;
				char *endptr;
				std::cout << "Please select a contact index." << std::endl;
				std::getline(std::cin, input);
				if (!std::cin)
					break;
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
