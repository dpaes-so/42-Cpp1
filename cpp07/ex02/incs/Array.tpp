/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 16:37:01 by dpaes-so          #+#    #+#             */
/*   Updated: 2026/05/06 17:19:46 by dpaes-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Array.hpp"


template<typename T> 
Array<T>::Array()
{
	this->_arr = new T[0];
}

template<typename T> 
Array<T>::Array(unsigned int n)
{
	this->_arr = new T[n];
}
template<typename T>
Array<T>::Array(const Array &source)
{
	this->_arr = NULL;
	*this = source;
}
template<typename T>
int Array<T>::size() const
{
	int i = 0;
	while(this->_arr[i])
	{
		i++;
	}
	return(i);
}

template<typename T>
Array<T> &Array<T>::operator=(const Array &source)
{
	if(this != &source)
	{
		delete[] this->_arr;
		this->_arr = new T[source.size()];
		for(int i = 0;source._arr[i];i++)
		{
			this->_arr[i] = source._arr[i];
		}
	}
	return(*this);
}

template<typename T>
T Array<T>::operator[](int n) const 
{
	if(n > this->size())
		throw std::invalid_argument("out of bounds");
	return(this->_arr[n]);
}
