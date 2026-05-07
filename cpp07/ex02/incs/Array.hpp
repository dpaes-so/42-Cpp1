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
	private:
		T *_arr;
		unsigned int _size;
	public:
		Array();
		~Array();
		Array(unsigned int n);
		Array(const Array &source);
		Array &operator=(const Array &source);
		T &operator[](unsigned int n);
		unsigned int size() const;


};
#endif