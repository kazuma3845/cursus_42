#include "Span.hpp"

int main()
{
	try
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		// sp.addNumber(500);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception catch is : " << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Span sp = Span(10000);
		sp.addMultiNumber(10000);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception catch is : " << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Span sp = Span(10);
		sp.addNumber(69);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception catch is : " << e.what() << std::endl;
	}
	return 0;
}
