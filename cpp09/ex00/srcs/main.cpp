/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 15:57:20 by dpaes-so          #+#    #+#             */
/*   Updated: 2026/05/27 19:00:34 by dpaes-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/BitcoinExchange.hpp"

bool first_parse(char *av, std::map <std::string, float> *db)
{
	(void)db;
	std::ifstream in(av); 
	std::ifstream data_bs("data.csv");
	std::string str;
	if(in.is_open() == 0)
		return(false);
	if(data_bs.is_open() == 0)
		return(false);
	std::getline(data_bs,str);
	std::cout << str;
	return true;
}
int main(int ac, char *av[])
{
	if(ac == 2)
	{		
		std::map<std::string,float> db;
		
		if(first_parse(av[1],&db) == false)
		{
			std::cerr << "input file dumb\n";
			return 1;
		}
	}
	else
	{
		std::cerr << "Invalid amount of arguments(./btc <input_file>)\n";
	}
	return 0;
}