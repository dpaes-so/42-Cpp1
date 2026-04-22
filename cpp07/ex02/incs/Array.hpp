/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 15:51:58 by dpaes-so          #+#    #+#             */
/*   Updated: 2026/04/21 17:11:02 by dpaes-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <iostream>
// #include "../srcs/array.tpp"

template<typename T> class Array
{
	public:
		T *_arr;
	public:
		// Array();
		Array(unsigned int n) {this->_arr = new T[n];this->_arr[0] =2;};
		// Array(const T&source);
		// Array &operator=(const T &source);
		int size() const
		{
			int i = 0;
			while(this->_arr[i])
				i++;
			return(i);
		};


};
#endif