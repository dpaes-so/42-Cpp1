/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 15:57:20 by dpaes-so          #+#    #+#             */
/*   Updated: 2026/05/08 18:30:09 by dpaes-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/easyfind.hpp"
#include <vector>
#include <list>

int main(void)
{
	std::vector<int> v;
	std::list<int> l;

	for(unsigned int i = 0;i < 5;i++)
		v.push_back(i);
	
	for(unsigned int i = 0;i < 5;i++)
		l.push_back(i);
	
	try
	{
		std::vector<int>::iterator it = easyfind(v,3);
		std::cout << "found: (" << *it << ") in the container\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::list<int>::iterator it = easyfind(l,-2);
		std::cout << "found: (" << *it << ") in the container\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}