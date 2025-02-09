#include <iostream> 
#include <string>  

int	main(int ac, char **av)
{
	int		i;
	unsigned long		c;
	std::string str;

	i = 1;
	c = 0;
	if (ac == 1)
		return (std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl, 0);
	while (av[i])
	{
		c = 0;
		str = av[i];
		while (c < str.length() ){
			std::cout << static_cast<char> (std::toupper(str[c]));
			c++;
		}
		i++;
	}
	std::cout << std::endl;
	return (0);
}