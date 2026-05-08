/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 16:37:01 by dpaes-so          #+#    #+#             */
/*   Updated: 2026/05/08 16:15:30 by dpaes-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Array.hpp"

template<typename T> 
Array<T>::Array()
{
	std::cout << "Array default constructor\n";
	this->_arr = new T[0];
	this->_size = 0;
}

template<typename T> 
Array<T>::Array(unsigned int n)
{
	std::cout << "Array size constructor\n";
	this->_arr = new T[n];
	this->_size = n;
}

template<typename T> 
Array<T>::~Array()
{
	std::cout << "Array default destructor\n";
	delete[] this->_arr;
}

template<typename T>
Array<T>::Array(const Array &source)
{
	std::cout << "Array copy constructor\n";
	this->_arr = NULL;
	*this = source;
}

template<typename T>
unsigned int Array<T>::size() const
{
	return(this->_size);
}

template<typename T>
Array<T> &Array<T>::operator=(const Array &source)
{
	std::cout << "Array assignment operator\n";
	if(this != &source)
	{
		delete[] this->_arr;
		this->_arr = new T[source.size()];
		this->_size = source._size;
		for(unsigned int i = 0; i < source._size;i++)
		{
			this->_arr[i] = source._arr[i];
		}
	}
	return(*this);
}

template<typename T>
T &Array<T>::operator[](unsigned int n) 
{
	if(n > this->size() || _size == 0)
		throw std::out_of_range("out of bounds");
	return(this->_arr[n]);
}

template<typename T>
const T &Array<T>::operator[](unsigned int n) const
{
	if(n > this->size() || _size == 0)
		throw std::out_of_range("out of bounds");
	return(this->_arr[n]);
}