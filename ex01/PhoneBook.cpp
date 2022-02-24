#include "PhoneBook.hpp"

void PhoneBook::print() {
	for (int i = 0; i < _nr_contacts; i ++) {
		_contacts[i].print_as_line(i);
	}
}

void PhoneBook::print_contact(int index) {
	_contacts[index].print();
}

PhoneBook::PhoneBook() : _next_contact(0), _nr_contacts(0) {}

void PhoneBook::add_contact() {
	_contacts[_next_contact].get_contact_info();
	_nr_contacts = std::max(_nr_contacts, _next_contact + 1);
	_next_contact = (_next_contact + 1) % 8;
}

bool PhoneBook::index_exists(int index) {
	return index >= 0 && index < _nr_contacts;
}
