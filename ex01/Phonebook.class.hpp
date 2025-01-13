#ifndef PHONEBOOK_CLASS_H
#define PHONEBOOK_CLASS_H

#include "Contact.class.hpp"
#include <iostream>

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
};

#endif