/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 17:32:10 by dpaes-so          #+#    #+#             */
/*   Updated: 2026/05/28 15:08:10 by dpaes-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Span.hpp"

Span::Span()
{
	std::cout << "Default Span constructor\n";
	this->_size = 0;
}

Span::Span(size_t size)
{
	std::cout << "Span constructor\n";
	this->_size = size;
}

Span::~Span()
{
	std::cout << "Default Span destructor\n";
}

std::vector<int> Span::getSpan() const
{
	return(this->v);
}

Span::Span(const Span &obj)
{
	std::cout << "copy Span constructor\n";
	*this = obj;
}


Span &Span::operator=(const Span &obj)
{
	std::cout << "Span copy assignment overload\n";
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
		if(n > N)
		{
			while (n >= N)
			{
				this->addNUmber(n);
				if(n == 0)
					break ;
				n--;
			}
		}
		else
		{
			while (n <= N)
			{
				this->addNUmber(n);
				n++;
			}
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

int Span::shortestSpan()
{
	if(v.size() == 0 || v.size() == 1)
		throw std::out_of_range("Span is to small!\n");

	size_t i = 0;
	int a,b,res;
	std::vector<int> temp;
	temp = this->v;
	int final = std::numeric_limits<int>::max();
	std::sort(temp.begin(),temp.end());
	while(i + 1 != temp.size())
	{
		a = temp.at(i);
		b = temp.at(i+1);
		res = b - a;
		if(res < final)
			final = res;
		i++;
	}
	return(final);
}

int Span::longestSpan()
{
	if(v.size() == 0 || v.size() == 1)
		throw std::out_of_range("Span is to small!\n");

	std::vector<int> temp = this->v;
	std::sort(temp.begin(),temp.end());
	return(temp.at(temp.size() - 1) - temp.at(0));
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