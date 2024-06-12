#include "Span.hpp"

Span::Span(unsigned int n) : _n(n)
{
}

Span::Span(Span const & src) : _n(src._n), _v(src._v)
{
}

Span & Span::operator=(Span const & src)
{
	if (this != &src)
	{
		_n = src._n;
		_v = src._v;
	}
	return *this;
}

Span::~Span()
{
}

const char * Span::SpanFullException::what() const throw()
{
	return "Span is full";
}

const char * Span::SpanNotEnoughNumbersException::what() const throw()
{
	return "Not enough numbers to calculate span";
}

void Span::addNumber(int n)
{
	if (_v.size() < _n)
		_v.push_back(n);
	else
		throw SpanFullException();
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (_v.size() + std::distance(begin, end) <= _n)
		_v.insert(_v.end(), begin, end);
	else
		throw SpanFullException();
}

int Span::shortestSpan()
{
	if (_v.size() < 2)
		throw SpanNotEnoughNumbersException();
	std::sort(_v.begin(), _v.end());
	int shortest = _v[1] - _v[0];
	for (unsigned int i = 1; i < _v.size(); ++i)
	{
		shortest = std::min(shortest, _v[i] - _v[i - 1]);
	}
	return shortest;
}

int Span::longestSpan()
{
	if (_v.size() < 2)
		throw SpanNotEnoughNumbersException();
	std::sort(_v.begin(), _v.end());
	return _v[_v.size() - 1] - _v[0];
}

