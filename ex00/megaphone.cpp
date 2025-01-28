#include <cctype>
#include <iostream>


int	main(int ac, char *av[])
{
	int	i;

	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (1);
	}
	i = 0;
	while (++i < ac)
	{
		std::string s = av[i];
		for (unsigned long j = 0; j < s.length(); j++)
		{
			if (j == 0)
			{
				if (s[0] != ' ')
				{
					s[0] = toupper(s[0]);
					std::cout << s[0];
				}
			}
			else if (j == s.length() - 1)
			{
				if (s[j] != ' ')
				{
					s[j] = toupper(s[j]);
					std::cout << s[j] << ' ';
				}
				else
					std::cout << s[j];
			}
			else
			{
				s[j] = toupper(s[j]);
				std::cout << (s[j]);
			}
		}
	}
	std::cout << std::endl;
	return (1);
}
