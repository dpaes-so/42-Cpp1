/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 15:57:20 by dpaes-so          #+#    #+#             */
/*   Updated: 2026/05/07 16:49:11 by dpaes-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Array.hpp"
#include "../incs/Array.tpp"

int main()
{
	{
		Array< int > ar(5);
		ar[0] = 42;
		std::cout << ar[0] << std::endl;
		std::cout << ar.size() << std::endl;
		Array< int > ar2(ar);
		std::cout << ar2.size() << std::endl;
		Array<int> ar3 = ar;
		std::cout << ar3.size() << std::endl;
	}
	{
		Array< char > ar(5);
		ar[0] = 42;
		std::cout << ar[0] << std::endl;
		std::cout << ar.size() << std::endl;
		Array< char > ar2(ar);
		std::cout << ar2.size() << std::endl;
		Array<char> ar3 = ar;
		std::cout << ar3.size() << std::endl;
	}
}