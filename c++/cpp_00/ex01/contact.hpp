#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <iostream>
# include <iomanip>

class Contact {

public :
	std::string	first;
	std::string	last;
	std::string	nick;
	std::string	abr_first;
	std::string	abr_last;
	std::string	abr_nick;
	std::string	phone_num;
	std::string	secret;
};

class PhoneBook {

public :
	int num;
	Contact Cons[8];

};

#endif