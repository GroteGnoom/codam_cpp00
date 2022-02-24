#include <string>
#include <iostream>
#include <iomanip>
#include "phonebook.hpp"

std::string trunc(std::string str) {
	if (str.size() <= 10)
		return str;
	str = str.substr(0,9).append(".");
	return str;
}

void get_contact_line(std::string prompt, std::string &field) {
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

Contact get_contact_info (void) {
	Contact new_contact;
	get_contact_line("first name", new_contact.first_name);
	get_contact_line("last name", new_contact.last_name);
	get_contact_line("nickname", new_contact.nickname);
	get_contact_line("phone number", new_contact.phone_number);
	get_contact_line("darkest secret", new_contact.darkest_secret);
	return new_contact;
}

void print_phonebook(PhoneBook phonebook) {
	for (int i = 0; i < phonebook.nr_contacts; i ++) {
		Contact contact = phonebook.contacts[i];
		std::cout << std::setw(10) << i+1 << "|";
		std::cout << std::setw(10) << trunc(contact.first_name) << "|";
		std::cout << std::setw(10) << trunc(contact.last_name) << "|";
		std::cout << std::setw(10) << trunc(contact.nickname) << std::endl;
	}
}

void print_contact(Contact contact) {
	std::cout << contact.first_name << std::endl;
	std::cout << contact.last_name << std::endl;
	std::cout << contact.nickname << std::endl;
	std::cout << contact.phone_number << std::endl;
	std::cout << contact.darkest_secret << std::endl;
}

int main() {
	PhoneBook phonebook;
	phonebook.next_contact = 0;
	phonebook.nr_contacts = 0;
	std::string input;
	while (1) {
		std::cout << "Please input 'ADD', 'SEARCH' OR 'EXIT'." << std::endl;
		std::getline(std::cin, input);
		if (input == "ADD") {
			phonebook.contacts[phonebook.next_contact] = get_contact_info();
			phonebook.nr_contacts = std::max(phonebook.nr_contacts, phonebook.next_contact + 1);
			phonebook.next_contact = (phonebook.next_contact + 1) % 8;
		}
		else if (input == "SEARCH") {
			print_phonebook(phonebook);
			while (1) {
				int index;
				std::cout << "Please select a contact index." << std::endl;
				std::getline(std::cin, input);
				char *endptr;
				index = strtol(input.c_str(), &endptr, 10);
				index--;
				if (strlen(endptr) > 0 || index < 0 || index >= phonebook.nr_contacts) {
					std::cout << "Invalid index." << std::endl;
					continue ;
				}
				print_contact(phonebook.contacts[index]);
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
