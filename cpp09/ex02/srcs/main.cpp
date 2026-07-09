/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 15:57:20 by dpaes-so          #+#    #+#             */
/*   Updated: 2026/07/09 13:43:57 by dpaes-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/PmergeMe.hpp"

int	main(int ac, char *av[])
{
	PmergeMe	cmerge;
	clock_t start;
	clock_t end;

	if (ac >= 2)
	{
		if (cmerge.parse_input(av))
		{
			start = clock();
			cmerge.Pmergevector();
			end = clock();
			double vector_time = static_cast<double>(end - start)* 1000000.0 / CLOCKS_PER_SEC;
			
			start = clock();
			cmerge.Pmergedeque();
			end = clock();
			double deque_time = static_cast<double>(end - start)* 1000000.0 / CLOCKS_PER_SEC;
			std::cout << "Time to process a range of " << ac - 1 << " elements with std::vector : " << vector_time << " us" << std::endl;
			std::cout << "Time to process a range of " << ac - 1 << " elements with std::deque : " << deque_time << " us" << std::endl;
		}
		else
			std::cerr << "Error: Bad input\n";
	}
	else
		std::cerr << "Invalid amount of arguments\n";
}