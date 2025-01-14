#include "Phonebook.class.hpp"


Phonebook::Phonebook(void){
	this->add_cursor = 0;
	return;
}

Phonebook::~Phonebook(void){
	return;
}

void	Phonebook::add(void){
	this->contacts[ this->add_cursor % 8] = _add_processing();
	this->add_cursor++;
}

int	Phonebook::_full_digit(std::string value){
	int i = 0;

	while (value[i])
	{
		if (!isdigit(value[i]))
			return (1);
		i++;
	}
	return (0);
}

Contact	Phonebook::_add_processing(void){
	std::string fn, ln, nm, ds, pn; 

	while (fn.empty()){
		std::cout << "Enter firstname:" << std ::endl;
		if (!std::getline (std::cin, fn))
			exit (1);
	}
	while (ln.empty()){
		std::cout << "Enter lastname:" << std ::endl;
		if (!std::getline (std::cin, ln))
			exit(1);
	}
	while (nm.empty()){
		std::cout << "Enter nickname:" << std ::endl;
		if (!std::getline (std::cin, nm))
			exit(1);
	}
	while (ds.empty()){
		std::cout << "Enter darkest secret:" << std ::endl;
		if (!std::getline (std::cin, ds))
			exit(1);
	}
	while (pn.empty() || _full_digit(pn)){
		std::cout << "Enter phone number:" << std ::endl;
		if (!std::getline (std::cin, pn))
			exit(1);
	}
	Contact contact(fn, ln, nm, ds, pn);
	return contact;
}

std::string Phonebook::_to_display(std::string value){
	std::string	value_display;
	if (value.length() > 10){
		value_display = value.substr(0,9) + ".";
		return value_display;
	}
	return value;
}

void	Phonebook::search(void) {
	int	index = 1;
	std::string index_ ;
	char tmp[2];
	
	std::cout << std::setw(10) << std::right << "index" << "|";
	std::cout << std::setw(10) << std::right << "first_name" << "|";
	std::cout << std::setw(10) << std::right << "last_name" << "|";
	std::cout << std::setw(10) << std::right << "nickname" << "|" << std::endl;
	
	while (this->contacts[index - 1].phone_number != "")
	{
		std::cout << std::setw(10) << std::right << (index) << "|";
		std::cout << std::setw(10) << std::right << _to_display(this->contacts[index - 1].first_name) << "|";
		std::cout << std::setw(10) << std::right << _to_display(this->contacts[index - 1].last_name) << "|";
		std::cout << std::setw(10) << std::right << _to_display(this->contacts[index - 1].nickname) << "|" << std::endl;
		index++;
	}
	index = -1;
	while (index < 1 || index > 8){
		std::cout << "Enter index between 1 and 8:" << std::endl;
		if (!std::getline(std::cin, index_))
			exit(1);
		tmp[0] = index_[0];
		tmp[1] = 0;
		index = atoi(tmp);
	}
	std::cout << std::setw(10) << std::right << "first name :" << (this->contacts[index - 1].first_name)  << std::endl;
	std::cout << std::setw(10) << std::right << "last name :" <<  (this->contacts[index - 1].last_name)  << std::endl;
	std::cout << std::setw(10) << std::right << "nickname :" <<  (this->contacts[index - 1].nickname)  << std::endl;
	std::cout << std::setw(10) << std::right << "phone number :" <<  (this->contacts[index - 1].phone_number )  << std::endl;
	std::cout << std::setw(10) << std::right << "darkest secret :" <<  (this->contacts[index - 1].darkest_secret) << std::endl;
}