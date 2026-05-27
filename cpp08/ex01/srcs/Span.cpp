/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: finn <finn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 17:32:10 by dpaes-so          #+#    #+#             */
/*   Updated: 2026/05/21 15:11:52 by finn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Span.hpp"

Span::Span()
{
	this->_size = 0;
}

Span::Span(size_t size)
{
	this->_size = size;
}

Span::~Span()
{
	
}

std::vector<int> Span::getSpan() const
{
	return(this->v);
}

Span::Span(const Span &obj)
{
	*this = obj;
}


Span &Span::operator=(const Span &obj)
{
	if(this != &obj)
	{
		this->v.erase(this->v.begin(),this->v.end());
		this->v = obj.v;
		this->_size = obj._size;
	}
	return(*this);
}

void Span::addNUmber(int n)
{
	if(this->v.size() < _size)
		v.push_back(n);
	else
		throw std::length_error("Span is already full!\n");
}

void Span::addNumberrange(size_t n,size_t N)
{
	try
	{
		while (n <= N)
		{
			this->addNUmber(n);
			n++;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

int Span::shortestSpan()
{
	size_t i = 0;
	size_t j = 0;
	int a,b;
	int res;
	int final = __INT_MAX__;

	if(v.size() == 0 || v.size() == 1)
		throw std::out_of_range("Span is to small!\n");
	while(i != v.size())
	{ 
		a = v.at(i);
		j = i + 1;
		while(j != v.size())
		{
			b = v.at(j);
			if(a > b)
				res = a - b;
			else
				res = b - a;
			if(res < final)
				final = res;	
			j++;
		}
		i++;
	}
	return(final);
}

int Span::longestSpan()
{
	size_t i = 0;
	size_t j = 0;
	int a,b;
	int res;
	int final = 0;

	if(v.size() == 0 || v.size() == 1)
		throw std::out_of_range("Span is to small!\n");
	while(i != v.size())
	{ 
		a = v.at(i);
		j = i + 1;
		while(j != v.size())
		{
			b = v.at(j);
			if(a > b)
				res = a - b;
			else
				res = b - a;
			if(res > final)
				final = res;	
			j++;
		}
		i++;
	}
	return(final);
}

std::ostream &operator<<(std::ostream &os,const Span &v)
{
	std::vector<int> obj = v.getSpan();
	for(size_t  i = 0;i < obj.size();i++)
	{
		os << obj.at(i) << " ";
	}
	os << std::endl;
	return(os);
}