/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 15:57:20 by dpaes-so          #+#    #+#             */
/*   Updated: 2026/05/06 15:36:45 by dpaes-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Array.hpp"
#include "../incs/Array.tpp"

int main()
{
	Array< int > ar(5);
	ar._arr[0] = 1;
	ar._arr[1] = 1;
	ar._arr[2] = 1;
	ar._arr[3] = 1;
	std::cout << ar.size() << std::endl;
	Array< int > ar2(ar);
	std::cout << ar2.size() << std::endl;
	Array<int> ar3 = ar;
	std::cout << ar3.size() << std::endl;
	std::cout << ar3[2] << std::endl;

	
}