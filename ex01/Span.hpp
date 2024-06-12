#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <exception>
#include <iostream>

class Span
{
private:
	unsigned int _n;
	std::vector<int> _v;
public:
	Span(unsigned int n);
	Span(Span const & src);
	~Span();
	Span & operator=(Span const & src);
	void addNumber(int n);
	void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
	int shortestSpan();
	int longestSpan();
	class SpanFullException : public std::exception
	{
	public:
		const char * what() const throw();
	};
	class SpanNotEnoughNumbersException : public std::exception
	{
	public:
		const char * what() const throw();
	};
};
#endif
