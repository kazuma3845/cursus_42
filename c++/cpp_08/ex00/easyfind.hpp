#pragma once

# include <iostream>
# include <vector>
# include <algorithm>

template <typename T>
void easyfind(T temp, int num)
{
	int i = 0;
	for (; temp[i]; i++)
	{
		if (temp[i] == num)
		{
			std::cout << "Num is " << i + 1 << "th possition" << std::endl;
			return ;
		}
	}
	std::cout << "Num is not in container" << std::endl;
}
