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

void PmergeMe::algo_vector()
{
    std::vector<int>::iterator it = this->_vect.begin();
    std::vector<int>::iterator ite = this->_vect.end();
    std::cout << "Before sort:\t";
    while (it != ite)
    {
        std::cout << " " << *it;
        it++;
    }
    std::cout << std::endl;
    clock_t start = clock();



















    clock_t end = clock();
    this->_timer = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
    std::vector<int>::iterator its = this->_vect.begin();
    std::cout << "After sort:\t";
    while (its != ite)
    {
        std::cout << " " << *its;
        its++;
    }
    std::cout << std::endl;
	std::cout << "Time to process a range of " << this->_vect.size() << " elements with std::vector : ";
    std::cout << std::fixed << std::setprecision(5) << this->_timer << " us" << std::endl;
}

void PmergeMe::algo_list()
{
     clock_t start = clock();
















    clock_t end = clock();
    this->_timer = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
	std::cout << "Time to process a range of " << this->_vect.size() << " elements with std::list : ";
    std::cout << std::fixed << std::setprecision(5) << this->_timer << " us" << std::endl;
}

const char *PmergeMe::ExceptionBadArgument::what() const throw()
{
	return "Bad Arguments";
}

const char *PmergeMe::ExceptionDoubleNumber::what() const throw()
{
	return "Doublon in numbers";
}
