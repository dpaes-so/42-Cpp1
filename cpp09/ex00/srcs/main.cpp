/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 15:57:20 by dpaes-so          #+#    #+#             */
/*   Updated: 2026/07/09 13:48:57 by dpaes-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/BitcoinExchange.hpp"

int main(int ac, char *av[])
{
	if(ac == 2)
	{		
		std::map<std::string,double> db;
		if(first_parse(av[1],&db) == false)		
			return (1);
		if(db.empty())
		{
			std::cerr << "Error: Data base is empty!" << std::endl;
			return(1);
		}
		start_matching(db,av[1]);
	}
	else
		std::cerr << "Invalid amount of arguments(./btc <input_file>)\n";
	return (0);
}
