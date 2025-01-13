#include "Contact.class.hpp"
#include "Phonebook.class.hpp"
#include <string>


int main(int ac, char **av)
{
	(void) ac;
	(void) av;
	std::string entry = "";
	Phonebook phonebook;

	while("EXIT" != entry)
	{
		std::cout << "Enter valid command please:" << std::endl;
		std::cin >> entry;
		if ("ADD" == entry)
			phonebook.add();
		if ("SEARCH" == entry)
			phonebook.search();
		
	}

	return (0);
}