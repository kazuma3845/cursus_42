#pragma once

class Span
{
	private:
		int N;
	public:
		Span();
		Span(int N);
		Span(const Span &f);
		Span operator=(const Span &f);
		~Span();

		void addNumber();
		void shortestSpan();
		void longestSpan();
};
