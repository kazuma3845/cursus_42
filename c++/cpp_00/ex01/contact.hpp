#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <iostream>
# include <iomanip>
using namespace std;

class Contact {

public :
	string	first;
	string	last;
	string	nick;
	string	abr_first;
	string	abr_last;
	string	abr_nick;
	string	phone_num;
	string	secret;
};

class PhoneBook {

public :
	int num;
	Contact Cons[8];

};

#endif