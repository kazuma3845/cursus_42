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

//------------------------------------------------------------------------------------------------------------------------------------------------------------

bool PmergeMe::print_vector(std::string name)
{
    bool isSorted = true;
    std::vector<int>::iterator it = this->_vect.begin();
    std::vector<int>::iterator ite = this->_vect.end();
    std::vector<int>::iterator next_it = it;
    next_it++;
    std::cout << name << " sort:\t";
    while (it != ite)
    {
        if (*it > *next_it && next_it != ite)
        {
           isSorted = false;
        }
        std::cout << " " << *it;
        it++;
        next_it++;
    }
    if (isSorted)
    {
        std::cout << " ==> List Sort" << std::endl;
        return false;
    }
    else
        std::cout << " ==> List Not Sort" << std::endl;
    return true;
}

void PmergeMe::algo_vector()
{
    if (print_vector("Before"))
    {
        clock_t start = clock();

        this->_vect = FordJohnsonVector(this->_vect, this->_vect.size()/2);
        if (this->_vect.front() > this->_vect.back())
        {
            std::vector<int> tmp;
            std::vector<int>::iterator it = this->_vect.begin();
            std::vector<int>::iterator ite = this->_vect.end();
            while (it != ite)
            {
                tmp.push_back(*it++);
                this->_vect.pop_back();
            }
            while (!tmp.empty())
            {
                this->_vect.push_back(tmp.back());
                tmp.pop_back();
            }
        }
        clock_t end = clock();
        this->_timer = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
    }
    else
        this->_timer = 0;
    print_vector("After");
	std::cout << "Time to process a range of " << this->_vect.size() << " elements with std::vector : ";
    std::cout << std::fixed << std::setprecision(5) << this->_timer << " us" << std::endl;
}

std::vector<int> PmergeMe::FordJohnsonVector(std::vector<int> base, unsigned int size)
{
    std::vector<int> left;
    std::vector<int> right;

    for(unsigned int i = 0; i < size; i++)
    {
        left.push_back(base.back());
        base.pop_back();
    }
    for(unsigned int i = 0; i < size; i++)
    {
        right.push_back(base.back());
        base.pop_back();
    }
    if (left.size() > 1)
        left = FordJohnsonVector(left, left.size()/2);
    if (right.size() > 1)
        right = FordJohnsonVector(right, right.size()/2);
    std::vector<int> result;
    result = UltimeMerge(right, left, base);
    return result;
}

std::vector<int> PmergeMe::UltimeMerge(std::vector<int> right, std::vector<int> left, std::vector<int> base)
{
    std::vector<int> result;

    if (right.back() > right.front())
    {
        // std::cout << "TEST1" << std::endl;
        while (!left.empty() || !right.empty() || !base.empty()) 
        {
        if ((!base.empty() && (left.empty() || left.back() < base.back()) && (right.empty() || right.back() < base.back())) || (left.empty() && right.empty()))
        {
            // std::cout << "Base: " << base.back() << std::endl;
            result.push_back(base.back());
            base.pop_back();
        }
        else if (right.empty() || (!left.empty() && left.back() > right.back())) 
        {
            if (!left.empty()) {
                // std::cout << "Left: " << left.back() << std::endl;
                result.push_back(left.back());
                left.pop_back();
            }
        }
        else {
            if (!right.empty()) {
                // std::cout << "Right: " << right.back() << std::endl;
                result.push_back(right.back());
                right.pop_back();
            }
        }
        }
    }
    else
    {
        // std::cout << "TEST2" << std::endl;
        while (!left.empty() || !right.empty() || !base.empty()) 
        {
        if ((!base.empty() && (left.empty() || left.back() > base.back()) && (right.empty() || right.back() > base.back())) || (left.empty() && right.empty()))
        {
            // std::cout << "Base: " << base.back() << std::endl;
            result.push_back(base.back());
            base.pop_back();
        }
        else if (right.empty() || (!left.empty() && left.back() < right.back())) 
        {
            if (!left.empty()) {
                // std::cout << "Left: " << left.back() << std::endl;
                result.push_back(left.back());
                left.pop_back();
            }
        }
        else {
            if (!right.empty()) {
                // std::cout << "Right: " << right.back() << std::endl;
                result.push_back(right.back());
                right.pop_back();
            }
        }
        }
    }
    // std::cout << "----MERGE----" << std::endl;
    return result;
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------


bool PmergeMe::print_list()
{
    bool isSorted = true;
    std::list<int>::iterator it = this->_lst.begin();
    std::list<int>::iterator ite = this->_lst.end();
    std::list<int>::iterator next_it = it;
    next_it++;
    while (it != ite)
    {
        if (*it > *next_it && next_it != ite)
           isSorted = false;
        it++;
        next_it++;
    }
    if (isSorted)
        return false;
    return true;
}

void PmergeMe::algo_list()
{
    if (print_list())
    {
        clock_t start = clock();
        this->_lst = FordJohnsonList(this->_lst, this->_lst.size()/2);
        if (this->_lst.front() > this->_lst.back())
        {
            std::list<int> tmp;
            std::list<int>::iterator it = this->_lst.begin();
            std::list<int>::iterator ite = this->_lst.end();
            while (it != ite)
                tmp.push_back(*it++);
            while (!this->_lst.empty())
                this->_lst.pop_back();
            while (!tmp.empty())
            {
                this->_lst.push_back(tmp.back());
                tmp.pop_back();
            }
        }
        clock_t end = clock();
        this->_timer = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
    }
    else
        this->_timer = 0;
	std::cout << "Time to process a range of " << this->_vect.size() << " elements with std::list : ";
    std::cout << std::fixed << std::setprecision(5) << this->_timer << " us" << std::endl;
}

std::list<int> PmergeMe::FordJohnsonList(std::list<int> base, unsigned int size)
{
    std::list<int> left;
    std::list<int> right;

    for(unsigned int i = 0; i < size; i++)
    {
        left.push_back(base.back());
        base.pop_back();
    }
    for(unsigned int i = 0; i < size; i++)
    {
        right.push_back(base.back());
        base.pop_back();
    }
    if (left.size() > 1)
        left = FordJohnsonList(left, left.size()/2);
    if (right.size() > 1)
        right = FordJohnsonList(right, right.size()/2);
    std::list<int> result;
    result = UltimeMergeList(right, left, base);
    return result;
}

std::list<int> PmergeMe::UltimeMergeList(std::list<int> right, std::list<int> left, std::list<int> base)
{
    std::list<int> result;

    if (right.back() > right.front())
    {
        // std::cout << "TEST1" << std::endl;
        while (!left.empty() || !right.empty() || !base.empty()) 
        {
        if ((!base.empty() && (left.empty() || left.back() < base.back()) && (right.empty() || right.back() < base.back())) || (left.empty() && right.empty()))
        {
            // std::cout << "Base: " << base.back() << std::endl;
            result.push_back(base.back());
            base.pop_back();
        }
        else if (right.empty() || (!left.empty() && left.back() > right.back())) 
        {
            if (!left.empty()) {
                // std::cout << "Left: " << left.back() << std::endl;
                result.push_back(left.back());
                left.pop_back();
            }
        }
        else {
            if (!right.empty()) {
                // std::cout << "Right: " << right.back() << std::endl;
                result.push_back(right.back());
                right.pop_back();
            }
        }
        }
    }
    else
    {
        // std::cout << "TEST2" << std::endl;
        while (!left.empty() || !right.empty() || !base.empty()) 
        {
        if ((!base.empty() && (left.empty() || left.back() > base.back()) && (right.empty() || right.back() > base.back())) || (left.empty() && right.empty()))
        {
            // std::cout << "Base: " << base.back() << std::endl;
            result.push_back(base.back());
            base.pop_back();
        }
        else if (right.empty() || (!left.empty() && left.back() < right.back())) 
        {
            if (!left.empty()) {
                // std::cout << "Left: " << left.back() << std::endl;
                result.push_back(left.back());
                left.pop_back();
            }
        }
        else {
            if (!right.empty()) {
                // std::cout << "Right: " << right.back() << std::endl;
                result.push_back(right.back());
                right.pop_back();
            }
        }
        }
    }
    // std::cout << "----MERGE----" << std::endl;
    return result;
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------

const char *PmergeMe::ExceptionBadArgument::what() const throw()
{
	return "Bad Arguments";
}

const char *PmergeMe::ExceptionDoubleNumber::what() const throw()
{
	return "Doublon in numbers";
}
