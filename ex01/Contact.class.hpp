#ifndef CONTACT_CLASS_H
#define CONTACT_CLASS_H

#include <string> 
#include <iostream>

class	Contact {

public:

	std::string	first_name;
	std::string	last_name;
	std::string	nickname; 
	std::string	darkest_secret; 
	std::string	phone_number;

	Contact(void);
	Contact( std::string fn, std::string ln, std::string nm, std::string ds, std::string pn);
	~Contact(void);


};

#endif