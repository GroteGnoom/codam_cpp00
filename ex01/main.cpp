#include <string>
#include <iostream>
#include <iomanip>
class Contact {
	public:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;
};

class PhoneBook {
	public:
		Contact contacts[8];
};

std::string trunc(std::string str) {
	if (str.size() < 10)
		return str;
	str = str.substr(0,9).append(".");
	return str;
}

int main() {
	int next_contact = 0;
	int nr_contacts = 0;
	PhoneBook phonebook;
	std::string input;
	while (1) {
		std::cout << "Please input 'ADD', 'SEARCH' OR 'EXIT'." << std::endl;
		std::getline(std::cin, input);
		if (input == "ADD") {
			Contact new_contact;
			std::cout << "Please enter first name:" << std::endl;
			std::getline(std::cin, new_contact.first_name);
			std::cout << "Please enter last name:" << std::endl;
			std::getline(std::cin, new_contact.last_name);
			std::cout << "Please enter nickname:" << std::endl;
			std::getline(std::cin, new_contact.nickname);
			std::cout << "Please enter phone number:" << std::endl;
			std::getline(std::cin, new_contact.phone_number);
			std::cout << "Please enter darkest secret:" << std::endl;
			std::getline(std::cin, new_contact.darkest_secret);
			phonebook.contacts[next_contact] = new_contact;
			next_contact = (next_contact + 1) % 8;
			nr_contacts = std::max(nr_contacts, next_contact);
		}
		if (input == "SEARCH") {
			for (int i = 0; i < nr_contacts; i ++) {
				Contact contact = phonebook.contacts[i];
				std::cout << std::setw(10) << i+1 << "|";
				std::cout << std::setw(10) << trunc(contact.first_name) << "|";
				std::cout << std::setw(10) << trunc(contact.last_name) << "|";
				std::cout << std::setw(10) << trunc(contact.nickname) << std::endl;
			}
			while (1) {
				int index;
				std::cout << "Please select a contact index." << std::endl;
				std::getline(std::cin, input);
				char *endptr;
				index = strtol(input.c_str(), &endptr, 10);
				index--;
				if (strlen(endptr) > 0 || index < 0 || index > nr_contacts) {
					std::cout << "Invalid index." << std::endl;
					continue ;
				}
				Contact contact = phonebook.contacts[index];
				std::cout << contact.first_name << std::endl;
				std::cout << contact.last_name << std::endl;
				std::cout << contact.nickname << std::endl;
				std::cout << contact.phone_number << std::endl;
				std::cout << contact.darkest_secret << std::endl;
				break ;
			}
		}
		if (input == "EXIT") {
			break;
		}
	}
}
