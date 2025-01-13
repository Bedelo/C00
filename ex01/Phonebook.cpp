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

Contact	Phonebook::_add_processing(void){
	std::string fn, ln, nm, ds;
	int pn = -1; 

	while (fn.empty()){
		std::cout << "Enter firstname ++:" << std ::endl;
		std::getline (std::cin, fn);
	}
	while (ln.empty()){
		std::cout << "Enter lastname:" << std ::endl;
		std::getline (std::cin, ln);
	}
	while (nm.empty()){
		std::cout << "Enter nickname:" << std ::endl;
		std::getline (std::cin, nm);
	}
	while (ds.empty()){
		std::cout << "Enter darkest secret:" << std ::endl;
		std::getline (std::cin, ds);
	}
	while (pn == -1){
		std::cout << "Enter phone number:" << std ::endl;
		std::cin >> pn;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore();
			pn = -1;
		}
	}
	Contact contact(fn, ln, nm, ds, pn);
	return contact;
}

void	Phonebook::search(void) {
	int	index = -1;
	while (index < 1 || index > 8){
		std::cout << "Enter index between 1 and 8:" << std::endl;
		std::cin >> index;
	}
	std::cout << this->contacts[index - 1].first_name << std::endl;
}