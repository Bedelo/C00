#include "Contact.class.hpp"
#include "Phonebook.class.hpp"
#include <string>
#include <csignal>
#include <cstdlib> 

// void signalHandler(int signum) {
// 	std::cout << "Signal :" << signum << ". Forced exit from the program." << std::endl;
// 	exit (1);
// }

int main(int ac, char **av)
{
	(void) ac;
	(void) av;
	std::string entry = "";
	Phonebook phonebook;
	// signal(SIGTERM, signalHandler);

	while("EXIT" != entry)
	{
		std::cout << "Enter valid command please (ADD, SEARCH, EXIT):" << std::endl;
		if(!std::getline(std::cin, entry)) {
			std::cout << "Forced exit from the program." << std::endl;
			return (1);
		}
		if ("ADD" == entry)
			phonebook.add();
		if ("SEARCH" == entry)
			phonebook.search();
	}

	return (0);
}