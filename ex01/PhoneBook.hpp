#ifndef PHONENOOK_HPP
#define PHONENOOK_HPP

#ifndef DEBUG
#define DEBUG 0
#endif

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
		int next_contact;
		int nr_contacts;
		Contact contacts[8];
};

#endif /* PHONENOOK_HPP */
