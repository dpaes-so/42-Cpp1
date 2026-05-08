/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 15:57:20 by dpaes-so          #+#    #+#             */
/*   Updated: 2026/05/08 15:47:15 by dpaes-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Iter.hpp"

int main(void)
{
	const int arr[] = {1, 2, 3, 4, 5};
	
	std::string sarr[] = {"hello", "world", "test"};

	std::cout << "Original array: ";
	iter(arr, 5, printInt);
	std::cout << std::endl;

	std::cout << "Original array: ";
	iter(arr, 5, printt);
	std::cout << std::endl;
	
	iter(arr, 5, incrementInt);
	std::cout << "After increment: ";
	iter(arr, 5, printInt);
	std::cout << std::endl;

	std::cout << "String array: ";
	iter(sarr, 3, printString);
	std::cout << std::endl;

	std::cout << "String array: ";
	iter(sarr, 3, printt);
	std::cout << std::endl;

	return 0;
}