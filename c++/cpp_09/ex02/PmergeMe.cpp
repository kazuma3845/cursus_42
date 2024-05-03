#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{

}

PmergeMe::PmergeMe(int argc, char **argv)
{
    for(int i = 1; i < argc; i++)
    {
        char* token = std::strtok(argv[i], " ");
        while (token != NULL)
        {
            for (int j = 0; token[j] != '\0'; j++)
            {
                if (!std::isdigit(token[j]))
                    throw ExceptionBadArgument();
            }
            int num = std::atoi(token);
            std::vector<int>::iterator it = this->_vect.begin();
            std::vector<int>::iterator ite = this->_vect.end();
            while (it != ite)
            {
                if (*it == num)
                    throw ExceptionDoubleNumber();
                it++;
            }
            if (num < 0 || num > INT_MAX)
                throw ExceptionBadArgument();
            this->_vect.push_back(num);
            this->_lst.push_back(num);
			std::cout << num << std::endl;
            token = std::strtok(NULL, " ");
        }
    }
}

PmergeMe::PmergeMe(const PmergeMe &f)
{
	(void)f;
}

PmergeMe::~PmergeMe()
{

}

PmergeMe &PmergeMe::operator=(const PmergeMe &f)
{
	(void)f;
	return *this;
}

void PmergeMe::algo()
{





	// std::cout << "Before sort:\t" << num << std::endl;
	// std::cout << "After sort:\t" << num << std::endl;
	// std::cout << "Time to process a range of " << len << " elements with std::vector :\t" << /*time <<*/ " us" << std::endl;
	// std::cout << "Time to process a range of " << len << " elements with std::list :\t" << /*time <<*/ " us" << std::endl;
}

const char *PmergeMe::ExceptionBadArgument::what() const throw()
{
	return "Bad Arguments";
}

const char *PmergeMe::ExceptionDoubleNumber::what() const throw()
{
	return "Doublon in numbers";
}
