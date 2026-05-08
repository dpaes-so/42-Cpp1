/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 15:51:58 by dpaes-so          #+#    #+#             */
/*   Updated: 2026/04/21 17:11:02 by dpaes-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP
#include <iostream>

template<typename T,typename F>
void iter(T *A, const unsigned int size,void (*f)(F &param))
{
	std::cout << "\ndiferent type template\n";
	for(unsigned int i = 0;i < size;i++)
		f(A[i]);
}

template<typename T>
void iter(T *A, const unsigned int size,void (*f)(T &param))
{
	std::cout << "\nsame type template\n";
	for(unsigned int i = 0;i < size;i++)
		f(A[i]);
}

template<typename T>
void printt(T print)
{
	std::cout << "my print: " << print << std::endl;
}

void printInt(int const& n) {
	std::cout << n << " ";
}

void incrementInt(int& n) {
	n += 5;
}

void printString(std::string const& s) {
	std::cout << s << " ";
}


#endif