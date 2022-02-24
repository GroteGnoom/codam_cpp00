#include "utils.hpp"
#include "Contact.hpp"
#include <iostream>
#include <iomanip>

void Contact::get_contact_info() {
	get_field("first name", _first_name);
	get_field("last name", _last_name);
	get_field("nickname", _nickname);
	get_field("phone number", _phone_number);
	get_field("darkest secret", _darkest_secret);
}

void Contact::print() {
	std::cout << "First name: " << _first_name << std::endl;
	std::cout << "Last name: " << _last_name << std::endl;
	std::cout << "Nickname: " << _nickname << std::endl;
	std::cout << "Phone number: " << _phone_number << std::endl;
	std::cout << "Darkest secret: " << _darkest_secret << std::endl;
}

void Contact::print_as_line(int index) {
	std::cout << std::setw(10) << index + 1 << "|";
	std::cout << std::setw(10) << trunc(_first_name) << "|";
	std::cout << std::setw(10) << trunc(_last_name) << "|";
	std::cout << std::setw(10) << trunc(_nickname) << std::endl;
}
