/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 15:45:31 by dpaes-so          #+#    #+#             */
/*   Updated: 2026/04/02 16:12:09 by dpaes-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ScalarConverter.hpp"

int main(int ac,char *av[])
{
	if(ac == 2)
	{
		ScalarConverter::convert(av[1]);
	}
	else
		std::cout << "Wrong number of arguments" << std::endl;
}