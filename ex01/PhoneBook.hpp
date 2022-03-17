#ifndef PHONENOOK_HPP
#define PHONENOOK_HPP

#include "Contact.hpp"
#include <array>

class PhoneBook {
	public:
		PhoneBook();
		void add_contact();
		void print();
		bool index_exists(int index);
		void print_contact(int index);
	private:
		int _next_contact;
		int _nr_contacts;
		std::array<Contact, 8> _contacts;
};

#endif /* PHONENOOK_HPP */
