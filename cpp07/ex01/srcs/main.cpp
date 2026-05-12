/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 15:57:20 by dpaes-so          #+#    #+#             */
/*   Updated: 2026/05/12 15:29:23 by dpaes-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Iter.hpp"

int main(void)
{
	const int arr[] = {1, 2, 3, 4, 5};
	int arr2[] = {1, 2, 3, 4, 5};
	
	std::string sarr[] = {"hello", "world", "test"};

	std::cout << "const array, const print";
	::iter(arr, 5, printInt);
	std::cout << std::endl;

	std::cout << "const array, same type print";
	::iter(arr, 5, printt);
	std::cout << std::endl;

	std::cout << "no const array, same type print";
	::iter(arr2, 5, printt);
	std::cout << std::endl;
	
	std::cout << "no const no const";
	::iter(arr2, 5, incrementInt);
	std::cout << std::endl;

	std::cout << "no const string, const print";
	::iter(sarr, 3, printString);
	std::cout << std::endl;
	return 0;
}