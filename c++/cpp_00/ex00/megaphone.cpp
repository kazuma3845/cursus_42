#include <iostream>

void ft_print(char *str)
{
	int i = -1;

	if (str)
		while (str[++i])
			std::cout << (char)toupper(str[i]);
}

int main(int argc, char **argv)
{
	int i = 0;

	if (argc >= 2)
	{
		while (argv[++i])
		{
			if (i > 1)
			std::cout << " ";
			ft_print(argv[i]);
		}
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::cout << std::endl;
	return 0;
}
