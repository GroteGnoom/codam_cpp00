#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
	public:
		void print();
		void print_as_line(int index);
		void get_contact_info();
	private:
		std::string _first_name;
		std::string _last_name;
		std::string _nickname;
		std::string _phone_number;
		std::string _darkest_secret;
};

#endif //CONTACT_HPP
