#include "utiles.hpp"

int main()
{
	string input;

	while (1)
	{
		cout << "Write ADD, SEARCH or EXIT" << endl;
		getline(cin, input);
		if (input == "EXIT")
			break ;
		else if (input == "ADD")
		{
			cout << "ADD" << endl;
		}
		else if (input == "SEARCH")
		{
			cout << "SEARCH" << endl;
		}
	}
	return 0;
}
