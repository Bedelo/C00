#ifndef PHONEBOOK_CLASS_H
#define PHONEBOOK_CLASS_H

#include "Contact.class.hpp"
#include <iostream>
#include <string>
#include <iomanip> 
#include <cctype>
#include <cstdlib> 

class Phonebook {

public:
	
	int			add_cursor;
	Contact		contacts[8];

	Phonebook(void);
	~Phonebook(void);

	void add(void);
	void search(void);

private:
	Contact _add_processing(void);
	std::string _to_display(std::string value);
	int	_full_digit(std::string value);
};

#endif