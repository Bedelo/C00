#include <iostream> 
#include <string>  
#include <stdio.h>

void toUpperCase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		std::cout << static_cast<char> (toupper(str[i++]));
}

int	main(int ac, char **av)
{
	int		i;

	i = 1;
	if (ac == 1)
		return (std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl, 0);
	while (av[i])
	{
		toUpperCase(av[i]);
		i++;
	}
	std::cout << std::endl;
	return (0);
}